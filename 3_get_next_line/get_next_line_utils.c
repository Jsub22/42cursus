/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 17:42:35 by subjeong          #+#    #+#             */
/*   Updated: 2024/11/24 01:59:19 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && (i + 1) < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		len;

	len = ft_strlen(s);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (--len >= 0)
		arr[len] = s[len];
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*arr;
	int		len;
	int		i;
	int		idx;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	idx = 0;
	i = 0;
	while (s1 && s1[i])
		arr[idx++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		arr[idx++] = s2[i++];
	arr[len] = '\0';
	return (arr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	while (ptr[i] != (char)c)
	{
		if (ptr[i] == '\0')
		{
			if (c == '\0')
				return (&ptr[i]);
			else
				return (NULL);
		}
		i++;
	}
	return (&ptr[i]);
}
