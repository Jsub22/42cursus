/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_ab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:36 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/14 20:55:08 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	rrab(t_stack **ss)
{
	t_stack *tmp;
	t_stack *last;

	if (*ss != NULL && (*ss)->prev != NULL)
	{
		tmp = *ss;
		while (tmp->prev != NULL)
            tmp = tmp->prev;
		last = tmp;
        tmp = *ss;
        while (tmp->prev != last)
            tmp = tmp->prev;
        tmp->prev = NULL;
        last->prev = *ss;
        *ss = last;

		// org = (*ss)->prev;
		// tmp = *ss;
		// while (tmp->prev != NULL)
		// 	tmp = tmp->prev;
		// (*ss)->prev = NULL;
		// tmp->prev->prev = *ss;
		// tmp->prev = NULL;
		// *ss = org;
	}
}

void	rra(t_stack **aa)
{
	rrab(aa);
	ft_putstr_fd("rra\n", 1);
}
void	rrb(t_stack **bb)
{
	rrab(bb);
	ft_putstr_fd("rrb\n", 1);
}
void	rrr(t_stack **aa, t_stack **bb)
{
	rrab(aa);
	rrab(bb);
	ft_putstr_fd("rrr\n", 1);
}