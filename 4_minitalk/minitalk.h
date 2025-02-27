/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:25 by subjeong          #+#    #+#             */
/*   Updated: 2025/02/27 16:01:52 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	int		bit;
	int		c;
	char	*msg;
} t_data;

void	ft_error_exit(char *msg);
void	ft_set_sigaction(struct sigaction *sa);
void	ft_send_signal(pid_t pid, int signo);


void	ft_parse_char(pid_t pid, char c);
void	ft_parse_int(pid_t pid, int num);

char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *nptr);

#endif