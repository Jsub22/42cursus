/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:41:45 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/24 15:25:31 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
