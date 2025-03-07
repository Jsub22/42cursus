/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigaction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 19:09:45 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 15:26:16 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error_exit(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}

void	ft_set_sigaction(struct sigaction *sa)
{
	if (sigaction(SIGUSR1, sa, NULL) < 0)
		ft_putstr_fd("Error : SIGUSR1 신호를 설정하지 못했습니다.", 1);
	if (sigaction(SIGUSR2, sa, NULL) < 0)
		ft_putstr_fd("Error : SIGUSR2 신호를 설정하지 못했습니다.", 1);
}

void	ft_send_signal(pid_t pid, int signo)
{
	if (signo == SIGUSR1)
	{
		if (kill(pid, signo) < 0)
			ft_error_exit("Error : SIGUSR1 신호를 보내지 못했습니다.");
	}
	else if (signo == SIGUSR2)
	{
		if (kill(pid, signo) < 0)
			ft_error_exit("Error : SIGUSR2 신호를 보내지 못했습니다.");
	}
}