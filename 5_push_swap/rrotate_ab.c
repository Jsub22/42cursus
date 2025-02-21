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
}
void	rrb(t_stack **bb)
{
	rrab(bb);
}
void	rrr(t_stack **aa, t_stack **bb)
{
	rrab(aa);
	rrab(bb);
}