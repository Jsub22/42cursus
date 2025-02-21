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
}
void	sb(t_stack **bb)
{
	sab(bb);
}
void	ss(t_stack **aa, t_stack **bb)
{
	sa(aa);
	sb(bb);
}