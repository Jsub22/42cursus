/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:12 by subjeong          #+#    #+#             */
/*   Updated: 2025/02/27 16:02:52 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_client_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;

	if (signo == SIGUSR1)
	{
		ft_putstr_fd("Error : ...\n", 1);
	}
	else if (signo == SIGUSR2)
	{
		ft_putstr_fd("Success : 연결에 성공했습니다.\n", 1);
		exit(0);
	}
}

static void	ft_send_msg(pid_t pid, char *msg)
{
	int idx;
	int	bit;

	idx = 0;
	bit = 0;
	while (msg[idx] != '\0')
	{
		while (bit < 8)
		{
			if ((msg[idx] >> bit) & 1)
				ft_send_signal(pid, SIGUSR1);
			else
				ft_send_signal(pid, SIGUSR2);
		}
		bit--;
	}
	if (msg[idx] == '\0')
	{
		while (bit < 8)
		{
			ft_send_signal(pid, SIGUSR2);
			bit--;
		}
		// pause();
	}
}

int	main (int argc, char **argv)
{
	struct sigaction sa;

	if (argc != 3)
		ft_error_exit("Error: ./client [Server PID] [Message] 으로 입력해 주세요.\n");
	else if (kill(ft_atoi(argv[1]), SIGUSR1) < 0)
		ft_error_exit("Error: 존재하지 않는 Server PID 입니다.\n");
	// else
	// 	pause();

	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = ft_client_handler;

	sigemptyset(&sa.sa_mask);
	ft_set_sigaction(&sa);

	ft_putstr_fd("전송 대상 서버의 PID : [ ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);
	ft_putstr_fd(" ]\n", 1);

	ft_send_msg(ft_atoi(argv[1]), argv[2]);

	return (0);
}
