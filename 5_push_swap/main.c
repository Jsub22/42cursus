#include "main.h"

int main(int argc, char *argv[])
{
	t_stack *aa;
	t_stack *bb;

	if (argc == 1 || \
	is_valid_args(argc, argv) == -1 ||
	!init_stack(&aa, &bb) ||
	!pill_stack(&aa, argc, argv) ||
	!push_swap(&aa, &bb))
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	else
	{
		ft_putstr_fd("Success\n", 1);
		// ft_putstr_fd("\n[result : AA stack]\n", 1);
		// ptr_stack(&aa);
		// ft_putstr_fd("\n[result : BB stack]\n", 1);
		// ptr_stack(&bb);
		return (0);
	}
}
