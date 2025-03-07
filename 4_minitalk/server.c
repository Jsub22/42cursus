/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:19 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 19:15:11 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	init_var(long unsigned int *bit, int *data)
{
	*bit = 0;
	*data = 0;
}

static char	*ft_make_arr(int data)
{
	char	*arr;

	arr = ft_calloc((data + 1), sizeof(char));
	if (!arr)
		ft_error_exit("Error : 배열 할당을 실패했습니다.\n");
	arr[data] = '\0';
	return (arr);
}

static void	ft_print_arr(char **msg, int *idx)
{
	ft_putstr_fd(*msg, 1);
	ft_putstr_fd("\n", 1);
	if (*msg)
		free(*msg);
	*msg = NULL;
	*idx = 0;
}

static void	ft_server_handler(int signo, siginfo_t *siginfo, void *context)
{
	static t_data	server;

	usleep(124);
	(void)context;
	if ((signo == SIGUSR2) && !server.msg)
		server.data |= 1 << (((sizeof(int) * 8) - 1) - server.bit);
	else if ((signo == SIGUSR2) && server.msg)
		server.data |= 1 << (((sizeof(char) * 8) - 1) - server.bit);
	++server.bit;
	if (!server.msg && server.bit == (sizeof(int) * 8))
	{
		server.msg = ft_make_arr(server.data);
		init_var(&server.bit, &server.data);
	}
	else if (server.msg && server.bit == (sizeof(char) * 8))
	{
		server.msg[server.idx++] = (char)server.data;
		if (server.data == '\0')
		{
			ft_print_arr(&server.msg, &server.idx);
			ft_send_signal(siginfo->si_pid, SIGUSR2);
		}
		init_var(&server.bit, &server.data);
	}
	ft_send_signal(siginfo->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

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
