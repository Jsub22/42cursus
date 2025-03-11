/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:12 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 19:27:05 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_client_handler(int signo, siginfo_t *siginfo, void *context)
{
	(void)siginfo;
	(void)context;
	if (signo == SIGUSR2)
	{
		ft_putstr_fd("Success : 모든 전송이 끝났습니다.\n", 1);
		exit(0);
	}
	else if (signo != SIGUSR1)
	{
		ft_error_exit("Error : 유효한 신호가 아닙니다.\n");
	}
}

void	ft_send_char(pid_t pid, char msg)
{
	int		bitshift;

	bitshift = ((sizeof(char) * 8) - 1);
	while (bitshift >= 0)
	{
		if (((msg >> bitshift) & 1) == 0)
			ft_send_signal(pid, SIGUSR1);
		else
			ft_send_signal(pid, SIGUSR2);
		pause();
		--bitshift;
	}
}

void	ft_send_int(pid_t pid, int len)
{
	int		bitshift;

	bitshift = ((sizeof(int) * 8) - 1);
	while (bitshift >= 0)
	{
		if (((len >> bitshift) & 1) == 0)
			ft_send_signal(pid, SIGUSR1);
		else
			ft_send_signal(pid, SIGUSR2);
		pause();
		--bitshift;
	}
}

static void	ft_send_msg(pid_t pid, char *msg)
{
	int	idx;

	ft_send_int(pid, ft_strlen(msg) + 1);
	idx = 0;
	while (msg[idx] != '\0')
	{
		ft_send_char(pid, msg[idx]);
		idx++;
	}
	ft_send_char(pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		ft_error_exit("Error: ./client [Server PID] [Message] 으로 입력해 주세요.\n");
	if (kill(ft_atoi(argv[1]), SIGUSR1) < 0)
		ft_error_exit("Error: 존재하지 않는 Server PID 입니다.\n");
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = ft_client_handler;
	sigemptyset(&sa.sa_mask);
	ft_set_sigaction(&sa);
	ft_putstr_fd("전송 대상 서버의 PID : [ ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);
	ft_putstr_fd(" ]\n", 1);
	ft_send_msg((pid_t)ft_atoi(argv[1]), argv[2]);
	return (0);
}
