/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:46 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/14 21:01:18 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	sab(t_stack **ss)
{
	int		n;

	if (*ss != NULL && (*ss)->prev != NULL)
	{
		n = (*ss)->num;
		(*ss)->num = (*ss)->prev->num;
		(*ss)->prev->num = n;
	}
}

void	sa(t_stack **aa)
{
	sab(aa);
	ft_putstr_fd("sa\n", 1);
}
void	sb(t_stack **bb)
{
	sab(bb);
	ft_putstr_fd("sb\n", 1);
}
void	ss(t_stack **aa, t_stack **bb)
{
	sa(aa);
	sb(bb);
	ft_putstr_fd("ss\n", 1);
}