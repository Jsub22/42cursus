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
	pab(aa, bb);
}
void	pb(t_stack **aa, t_stack **bb)
{
	pab(bb, aa);
}
