/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 19:22:47 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/07 20:31:25 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include "./libft/libft.h"

typedef struct s_spot
{
	int x;
	int y;
} t_spot;

typedef struct s_data
{
	int	fd;
	char **map;
	int safe;
	int	presure;
	t_spot	stt;
	t_spot	end;
	t_spot	use;
}	t_data;

void	ft_error_exit(char *msg);

void	set_vars(t_data *data);
void	set_map(t_data *data);
int		drawMap(t_data *data);
void	set_userWASD();

int		isValidMapForm(char *filename);
int		isValidMapData(t_data *data);
int		isValidMapDFS(t_data *data);

#endif