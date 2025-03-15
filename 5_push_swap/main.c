/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:11 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/15 23:36:48 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int main(int argc, char *argv[])
{
	t_stack *aa;
	t_stack *bb;

	aa = NULL;
	bb = NULL;
	if (argc < 2)
		ft_error_exit1("Error\n: 매개변수 부족 또는 초과\n");
	if (is_valid_args(argc, argv) == -1)
		ft_error_exit1("Error\n: 매개변수 유효성 없음\n");
	if (set_stacks(&aa, argc, argv) == -1)
		ft_error_exit2(&aa, &bb, "Error\n: 스택 생성 실패\n");
	if(push_swap(&aa, &bb) == -1)
		ft_error_exit2(&aa, &bb, "Error\n: 스택 스왑 실패\n");
	if (aa)
		free_stack(&aa);
	if (bb)
		free_stack(&bb);
	return (0);
}
