#include "main.h"

/**************************/
#include <stdio.h>
static void print_stack(t_stack **ss) {
    t_stack *cur = *ss;

    if (cur == NULL) {
        printf("[ Stack is empty. ]\n");
        return;
    }
    printf("[ ");
    while (cur != NULL) {
        printf("%d ", cur->num);
        cur = cur->prev;
    }
    printf("]\n");
}
/**************************/

int	push_swap(t_stack **aa, t_stack **bb)
{
	printf("*start*\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	sa(aa);
	printf("***sa**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	sb(bb);
	printf("***sb**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	ss(aa, bb);
	printf("***ss**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	pa(aa, bb);
	printf("***pa**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	pb(aa, bb);
	printf("***pb**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	ra(aa);
	printf("***ra**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	rb(bb);
	printf("***rb**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	rr(aa, bb);
	printf("***rr**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	rra(aa);
	printf("**rra**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	rrb(bb);
	printf("**rrb**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	rrr(aa, bb);
	printf("**rrr**\n");
	print_stack(aa);
	print_stack(bb);
	printf("*******\n");

	return (1);
}