/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:29:11 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/12 17:49:20 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*arr;
	int		len;
	int		sign;

	len = get_len(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (--len >= 0)
	{
		if (len == 0 && sign == -1)
			arr[0] = '-';
		else
		{
			arr[len] = ((n % 10) * sign) + '0';
			n /= 10;
		}
	}
	return (arr);
}
