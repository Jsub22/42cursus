/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:42 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/15 23:40:45 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	free_stack(t_stack **ss)
{
	t_stack *tmp;

	while (*ss)
	{
		tmp = *ss;
		*ss = (*ss)->prev;
		free(tmp);
	}
}

int	set_stacks(t_stack **aa, int argc, char *argv[])
{
    t_stack *tmp;
    int i;

    i = argc - 1;
    while (i > 0)
    {
        tmp = (t_stack *)malloc(sizeof(t_stack));
		if (!tmp)
		{
			free_stack(aa);
			return (-1);
		}
        tmp->num = (int)ft_atolli(argv[i]);
		if (*aa == NULL)
        	tmp->prev = NULL;
        else
			tmp->prev = *aa;
        *aa = tmp;
        i--;
    }
    return (1);
}

/***** *****/
#include <limits.h>
/***** *****/
int	is_sorted_stack(t_stack **aa, t_stack **bb)
{
	t_stack *cur;
	int max;

	cur = *aa;
	max = INT_MIN;
	while (cur != NULL) {
		if (max < cur->num)
			max = cur->num;
		else
			return (-1);
		cur = cur->prev;
	}
	cur = *bb;
	while (cur != NULL) {
		if (max < cur->num)
			max = cur->num;
		else
			return (-1);
		cur = cur->prev;
	}
	return (1);
}

int	find_stack_max_cnt(t_stack **ss)
{
	t_stack *cur;
	int max;
	int	cnt;

	cur = *ss;
	if (cur == NULL)
		return (-1);
	max = INT_MIN;
	while (cur != NULL) {
		if (max < cur->num)
			max = cur->num;
		cur = cur->prev;
	}
    if (max == 0)
        return 0;
    cnt = 0;
    while (max > 0) {
        cnt++;
        max >>= 1;
    }
    return cnt;
}

int get_stack_len(t_stack **ss)
{
	t_stack *cur;
	int	cnt;

	cnt = 0;
	cur = *ss;
	if (cur == NULL)
		return (cnt);
	while (cur != NULL) {
		cnt++;
		cur = cur->prev;
	}
	return (cnt);
}

void	merge_stacks(t_stack **aa, t_stack **bb)
{

	while (get_stack_len(bb) > 0)
	{
		if(bb)
			pa(aa, bb);
		if(aa)
			ra(aa);
	}
	// t_stack *cur;

    // if (*aa == NULL) {
    //     *aa = *bb;
    //     *bb = NULL;
    // }
	// else
	// {
	// 	cur = *aa;
	// 	while (cur->prev != NULL) {
	// 		cur = cur->prev;
	// 	}
	// 	cur->prev = *bb;
	// 	*bb = NULL;
	// }
}
