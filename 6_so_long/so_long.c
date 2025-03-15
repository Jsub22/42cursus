/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:22:50 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 20:31:10 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data data;
	char *str = {"0", "1", "C", "E", "P"};

	// 필요한 변수들을 초기화함
	set_vars(&data);
	// map 파일이 ber형식인지 검사함
	if (!isValidMapForm("filename"))
	{
		;
	}
	// maps.ber 파일을 읽어서 map에 저장함
	// maps.ber 파일을 두 번 읽음
	// x 길이, y 길이를 읽어옴
	set_map(&data);

	// map의 유효성을 검사함
	if (!isValidMapData(&data))
	{
		;
	}

	// dfs로 길이 있는지 검사함
	if (!isValidMapDFS(&data))
	{
		;
	}
	// 맵을 그림
	drawMap(&data);
	// 사용자가 동작할 수 있도록 함
	set_userWASD();
	return (0);
}