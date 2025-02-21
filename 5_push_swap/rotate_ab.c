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
}
void	rb(t_stack **bb)
{
	rab(bb);
}
void	rr(t_stack **aa, t_stack **bb)
{
	ra(aa);
	rb(bb);
}