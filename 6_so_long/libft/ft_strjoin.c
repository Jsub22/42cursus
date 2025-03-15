/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:27:48 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/24 14:57:34 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
