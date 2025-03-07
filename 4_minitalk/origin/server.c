/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:10 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/05 17:07:12 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_handler(int signal)
{
	static int	bit;
	static char	letter;

	if (signal == SIGUSR1)
	{
		letter |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(letter, 1);
		bit = 0;
		letter = 0;
	}
}

int	main (int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
	{
		ft_putstr_fd("Error: ./server 으로 입력해 주세요.\n", 1);
		return (0);
	}
	ft_putstr_fd("Server PID : [ ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd(" ]\n", 1);
	ft_putstr_fd("메시지를 기다리는 중...\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
