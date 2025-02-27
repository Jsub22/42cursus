/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:19 by subjeong          #+#    #+#             */
/*   Updated: 2025/02/27 16:55:14 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server_handler(int signo, siginfo_t *siginfo, void *context)
{
	static t_data server;

	(void)context;
	if (server.bit == 0)
		server.c = 0;
	if (signo != SIGUSR1 && signo != SIGUSR2)
		return ;
	else if (signo == SIGUSR1)
		server.c |= (1 << server.bit);
	server.bit++;

	if (server.bit == 8)
	{
		if (server.c != 0)
		{
			server.msg = ft_strjoin(server.msg, ft_calloc(server.c, sizeof(char)));
			if (!server.msg)
				ft_error_exit("Error : 배열 할당을 실패했습니다.\n");
		}
		else
		{
			ft_putstr_fd(server.msg, 1);
			free(server.msg);
			ft_send_signal(siginfo->pid, SIGUSR1);
			pause();
		}
		server.bit = 0;
		server.c = 0;
	}
}

int	main (int argc, char **argv)
{

	struct sigaction sa;

	(void)argv;
	if (argc != 1)
		ft_error_exit("Error : ./server 으로 입력해 주세요.\n");

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_server_handler;
	sigemptyset(&sa.sa_mask);
	ft_set_sigaction(&sa);

	ft_putstr_fd("서버의 PID : [ ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" ]\n", 1);
	ft_putstr_fd("메시지를 기다리는 중...\n", 1);

	while (1)
		pause();
	return (0);
}

