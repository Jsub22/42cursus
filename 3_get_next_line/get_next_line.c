/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:41:44 by subjeong          #+#    #+#             */
/*   Updated: 2024/11/25 14:11:47 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*merge_line(char **line_buff, char **read_buff)
{
	char	*temp;

	if (*line_buff == NULL)
		return (ft_strdup(*read_buff));
	temp = ft_strjoin(*line_buff, *read_buff);
	if (*line_buff)
		free(*line_buff);
	*line_buff = NULL;
	return (temp);
}

static char	*return_line(char **line_buff, ssize_t read_size, int i)
{
	char	*ret;
	char	*new_buff;

	ret = NULL;
	new_buff = NULL;
	if (*line_buff && read_size != -1)
	{
		while ((*line_buff)[i] && (*line_buff)[i] != '\n')
			i++;
		if ((*line_buff)[i])
			i++;
		ret = (char *)malloc(sizeof(char) * (i + 1));
		if (!ret)
			return (NULL);
		ft_strlcpy(ret, *line_buff, i + 1);
		if (ft_strlen(*line_buff) - i > 0)
		{
			new_buff = ft_strdup(*line_buff + i);
			if (!new_buff)
				return (NULL);
		}
		free(*line_buff);
		*line_buff = new_buff;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	static char		*line_buff;
	char			*read_buff;
	ssize_t			read_size;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buff)
		return (NULL);
	read_size = read(fd, read_buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		read_buff[read_size] = '\0';
		line_buff = merge_line(&line_buff, &read_buff);
		if (ft_strchr(line_buff, '\n'))
			break ;
		read_size = read(fd, read_buff, BUFFER_SIZE);
	}
	if (read_buff)
		free(read_buff);
	return (return_line(&line_buff, read_size, 0));
}
