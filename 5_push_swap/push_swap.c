/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:27 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/16 00:49:07 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/**************************/
// #include <stdio.h>
// static void print_stack(t_stack **ss) {
//     t_stack *cur = *ss;

//     if (cur == NULL) {
//         printf("[ Stack is empty. ]\n");
//         return;
//     }
//     printf("[ ");
//     while (cur != NULL) {
//         printf("%d ", cur->num);
//         cur = cur->prev;
//     }
//     printf("]\n");
// }
/**************************/

// 그외의 알고리즘 (기수 정렬)
static int radix_sort(t_stack **aa, t_stack **bb, int place)
{
	int	aa_len;
	int bb_len;
	int	i;

	// int aa_cnt;
	// int bb_cnt;

	aa_len = get_stack_len(aa);
	bb_len = get_stack_len(bb);
	// printf("\naa_len:%d bb_len:%d\n", aa_len, bb_len);

	i = 0;
	// aa_cnt = 0;
	// bb_cnt = 0;
	while (i < aa_len && (*aa) != NULL) {
		if ((((*aa)->num >> place) & 1) == 0)
		{
			// a->b 보내고 rb 스킵 후(X N번), 다음 a에서 ra 해야 될 때(X N번) -> 만약 남은 게 있으면 제거해줘야 함.
			// b->a 보내고 ra 스킵 후(X N번), 다음 b에서 rb 해야 될 때(X N번) -> 그리고, 스왑처리해서 한번에 계산해줄 수도 있음...
			// ra 스킵 후(X N번), 다음 b에서 rb 해야 될 때(X N번)

			// printf("\n!!!place:%d num:%d->%d!!!\n", place, (*aa)->num, ((*aa)->num >> place) & 1);
			if(aa)
				ra(aa);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
		}
		else
		{
			// printf("\n!!!place:%d num:%d->%d!!!\n", place, (*aa)->num, ((*aa)->num >> place) & 1);
			if(aa)
				pb(aa, bb);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
			if(bb)
				rb(bb);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
		}
		// // cur = cur->prev;
		// if(cur == NULL)
		// 	printf("NULL\n\n\n");
		i++;
		if (is_sorted_stack(aa, bb) == 1)
		{
			// ft_putstr_fd("정렬 완료 1", 1);
			return (1);
		}
	}
	i = 0;
	// aa_cnt = 0;
	// bb_cnt = 0;
	while (i < bb_len && (*bb) != NULL) {
		if ((((*bb)->num >> place) & 1) == 0)
		{
			// printf("\n!!!place:%d num:%d->%d!!!\n", place, (*bb)->num, ((*bb)->num >> place) & 1);
			if(bb)
				pa(aa, bb);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
			if(aa)
				ra(aa);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
		}
		else
		{
			// printf("\n!!!place:%d num:%d->%d!!!\n", place, (*bb)->num, ((*bb)->num >> place) & 1);
			if(bb)
				rb(bb);
			// printf("*******\n");
			// print_stack(aa);
			// print_stack(bb);
			// printf("*******\n");
		}
		// cur = cur->prev;
		i++;
		if (is_sorted_stack(aa, bb) == 1)
		{
			// ft_putstr_fd("정렬 완료 2", 1);
			return (1);
		}
	}
	// ft_putstr_fd("아직 머럿음 ㅋㅋ~", 1);
	return (2);
}

int	push_swap(t_stack **aa, t_stack **bb)
{
	int	max_cnt;
	int	i;
	int	status;

	if (is_sorted_stack(aa, bb) == 1)
	{
		// ft_putstr_fd("aa", 1);
		return (1);
	}
	// hard_sort_3_data();
	// hard_sort_5_data();
	/*정렬 시작*/
	// printf("\n*******\n");
	// print_stack(aa);
	// print_stack(bb);
	// printf("*******\n");
	// ft_putstr_fd("정렬 시작~~!", 1);

	max_cnt = find_stack_max_cnt(aa);
	if (max_cnt == -1)
		return (-1);
	i = 0;
	while (i < max_cnt)
	{
		status = radix_sort(aa, bb, i);
	// return (-1) 할 만한 오류 사항이 있는가?
		if (status == 1)
			break ;
		else if (status == -1)
			return (-1);
		i++;
	}
	// 배열 aa로 합쳐...
	// printf("\n*******\n");
	// print_stack(aa);
	// print_stack(bb);
	// printf("*******\n");
	merge_stacks(aa, bb);
	// printf("\n*******\n");
	// print_stack(aa);
	// print_stack(bb);
	// printf("*******\n");
	return (1);
}


// int	push_swap(t_stack **aa, t_stack **bb)
// {
// 	printf("*start*\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	sa(aa);
// 	printf("***sa**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	sb(bb);
// 	printf("***sb**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	ss(aa, bb);
// 	printf("***ss**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	pa(aa, bb);
// 	printf("***pa**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	pb(aa, bb);
// 	printf("***pb**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	ra(aa);
// 	printf("***ra**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	rb(bb);
// 	printf("***rb**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	rr(aa, bb);
// 	printf("***rr**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	rra(aa);
// 	printf("**rra**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	rrb(bb);
// 	printf("**rrb**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	rrr(aa, bb);
// 	printf("**rrr**\n");
// 	print_stack(aa);
// 	print_stack(bb);
// 	printf("*******\n");

// 	return (1);
// }