/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:25 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 18:39:21 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include "./libft/libft.h"

typedef struct s_data
{
	long unsigned int	bit;
	int					idx;
	int					data;
	int					pid;
	char				*msg;
}	t_data;

void	ft_error_exit(char *msg);
void	ft_set_sigaction(struct sigaction *sa);
void	ft_send_signal(pid_t pid, int signo);

#endif