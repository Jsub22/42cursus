/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:07:21 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/05 17:07:22 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_bit(int pid, char input)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((input & (1 << bit)) != 0)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		usleep(10);
		bit++;
	}
}

static void	ft_send_str(int pid, char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		ft_send_bit(pid, input[i]);
		i++;
	}
	ft_send_bit(pid, '\n');
	ft_send_bit(pid, '\0');
}

int	main (int argc, char **argv)
{
	int	pid;

	if (argc == 3 && argv[2][0] != '\0')
	{
		pid = ft_atoi(argv[1]);
		ft_putnbr_fd(pid, 1);
		if (pid <= 100)
		{
			ft_putstr_fd("Error: Server PID가 틀립니다.\n", 1);
			return (0);
		}
		ft_send_str(pid, argv[2]);
	}
	else
	{
		ft_putstr_fd("Error: ./client [Server PID] [Message] 으로 입력해 주세요.\n", 1);
	}
	return (0);
}
