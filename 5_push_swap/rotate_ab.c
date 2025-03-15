/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:33 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/15 23:06:43 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	rab(t_stack **ss)
{
	t_stack *tmp;
	t_stack *first;

	if (*ss != NULL && (*ss)->prev != NULL)
	{
		first = *ss;
        tmp = *ss;
		*ss = (*ss)->prev;
        while (tmp->prev != NULL)
            tmp = tmp->prev;
        tmp->prev = first;
        first->prev = NULL;
	}
}

void	ra(t_stack **aa)
{
	rab(aa);
	ft_putstr_fd("ra\n", 1);
}
void	rb(t_stack **bb)
{
	rab(bb);
	ft_putstr_fd("rb\n", 1);
}
void	rr(t_stack **aa, t_stack **bb)
{
	ra(aa);
	rb(bb);
	ft_putstr_fd("rr\n", 1);
}