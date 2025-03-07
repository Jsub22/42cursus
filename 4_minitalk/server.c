/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:19 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 15:30:43 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_server_handler(int signo, siginfo_t *siginfo, void *context)
{
	static t_data server;
	static int idx;

	usleep(124);
	(void)context;

	// if (!server.msg && signo == SIGUSR1)
	// 	ft_putstr_fd("O", 1);
	// else if (!server.msg && signo == SIGUSR2)
	// 	ft_putstr_fd("T", 1);

	if ((signo == SIGUSR2) && !server.msg)
		server.data |= 1 << (((sizeof(int) * 8) - 1) - server.bit);
	else if ((signo == SIGUSR2) && server.msg)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bit);
	++server.bit;

	if (!server.msg && server.bit == (sizeof(int) * 8))
	{
			// ft_putchar_fd(server.data, 1);
			// ft_putnbr_fd(server.data, 1);
			// ft_putchar_fd(server.data+'0', 1);
			server.msg = ft_calloc((server.data + 1), sizeof(char));
			if (!server.msg)
				ft_error_exit("Error : 배열 할당을 실패했습니다.\n");
			server.msg[server.data + 1] = '\0';
		server.bit = 0;
		server.data = 0;
	}
	else if (server.msg && server.bit == (sizeof(char) * 8))
	{
		server.msg[idx++] = (char)server.data;
			// ft_putchar_fd((char)server.data, 1);
			if (server.data == '\0')
			{
				ft_putstr_fd(server.msg, 1);
				free(server.msg);
				server.msg = NULL;
				idx = 0;
				ft_send_signal(siginfo->si_pid, SIGUSR2);
			}
		server.bit = 0;
		server.data = 0;
	}
	ft_send_signal(siginfo->si_pid, SIGUSR1);
}

int	main (int argc, char **argv)
{
	struct sigaction sa;

	(void)argv;
	if (argc != 1)
		ft_error_exit("Error : ./server 으로 입력해 주세요.\n");

	sa.sa_flags = SA_SIGINFO | SA_RESTART;
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

