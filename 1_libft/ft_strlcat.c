/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:16:09 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/24 15:26:42 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d_len;
	size_t	s_len;
	size_t	i;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	i = 0;
	if (d_len > size)
		return (size + s_len);
	while (src[i] && d_len + i + 1 < size)
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (d_len != size)
	{
		dest[d_len + i] = '\0';
	}
	return (d_len + s_len);
}
