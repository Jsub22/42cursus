/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:48 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/22 15:36:54 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(char const *s, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (size);
}

static int	get_len(char const *s, char c, int stt)
{
	int	len;

	len = 0;
	while (s[stt + len] && s[stt + len] != c)
		len++;
	return (len);
}

static int	copy_datas(char const *s, char c, char **arr)
{
	int	idx;
	int	i;

	idx = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			arr[idx] = (char *)malloc(sizeof(char) * (get_len(s, c, i) + 1));
			if (arr[idx] == NULL)
			{
				while (idx > 0)
					free(arr[--idx]);
				free(arr);
				return (0);
			}
			ft_strlcpy(arr[idx++], &s[i], get_len(s, c, i) + 1);
			i += get_len(s, c, i);
		}
	}
	arr[idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;

	if (s == NULL)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (get_size(s, c) + 1));
	if (arr == NULL)
		return (NULL);
	if (copy_datas(s, c, arr) == 0)
		return (NULL);
	return (arr);
}
