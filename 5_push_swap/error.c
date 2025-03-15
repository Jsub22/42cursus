/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:28:00 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/14 20:01:02 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_error_exit1(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}


void	ft_error_exit2(t_stack **aa, t_stack **bb, char *msg)
{
	if (*aa)
		free_stack(aa);
	if (*bb)
		free_stack(bb);
	ft_putstr_fd(msg, 1);
	exit(1);
}