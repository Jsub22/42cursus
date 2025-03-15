/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:28:12 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/24 15:33:46 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*arr;
	int		len;
	int		idx;

	if (!s1 || !set)
		return (NULL);
	idx = 0;
	len = ft_strlen(s1);
	while (s1[idx] && ft_strchr(set, s1[idx]))
		idx++;
	while (idx < len && s1[len - 1] && ft_strrchr(set, s1[len - 1]))
		len--;
	arr = (char *)malloc(sizeof(char) * (len - idx + 1));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, &s1[idx], len - idx + 1);
	return (arr);
}
