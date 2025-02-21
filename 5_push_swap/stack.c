#include "main.h"

void	free_stack(t_stack **ss)
{
	t_stack *tmp;

	if (!ss || !*ss)
		return ;
	while (*ss)
	{
		tmp = *ss;
		*ss = (*ss)->prev;
		free(tmp);
	}
}

int	init_stack(t_stack **aa, t_stack **bb)
{
	*aa = NULL;
	*bb = NULL;
	// *aa = (t_stack *)malloc(sizeof(t_stack));
	// if (!aa || !*aa)
	// 	return (-1);
	// *bb = (t_stack *)malloc(sizeof(t_stack));
	// if (!bb || !*bb)
	// {
	// 	free_stack(aa);
	// 	free_stack(bb);
	// 	return (-1);
	// }
	// ft_putstr_fd("\n[init : AA stack]\n", 1);
	// ptr_stack(&(*aa));
	// ft_putstr_fd("\n[init : BB stack]\n", 1);
	// ptr_stack(&(*bb));
	return (1);
}

int pill_stack(t_stack **aa, int argc, char *argv[])
{
    t_stack *tmp;
    int i;

    i = 1;
    while (i < argc)
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
        i++;
    }
    return (1);
}





