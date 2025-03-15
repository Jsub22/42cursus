/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:20 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/15 22:54:40 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	pab(t_stack **s1, t_stack **s2)
{
	t_stack *tmp;

	if (*s1 != NULL)
	{
		tmp = *s1;
		*s1 = (*s1)->prev;
		if (*s2 == NULL)
        	tmp->prev = NULL;
        else
			tmp->prev = (*s2);
        *s2 = tmp;
	}
}

void	pa(t_stack **aa, t_stack **bb)
{
	pab(bb, aa);
	ft_putstr_fd("pa\n", 1);
}
void	pb(t_stack **aa, t_stack **bb)
{
	pab(aa, bb);
	ft_putstr_fd("pb\n", 1);
}
