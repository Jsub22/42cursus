/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:14:43 by subjeong          #+#    #+#             */
/*   Updated: 2024/12/17 18:11:06 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_uitoha(unsigned int n, char type)
{
	char			*arr;
	int				len;
	unsigned int	tmp;

	len = ft_hex_len(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (--len >= 0)
	{
		tmp = (n % 16);
		if (tmp < 10)
			arr[len] = tmp + '0';
		else if (type == 'x')
			arr[len] = (tmp - 10) + 'a';
		else if (type == 'X')
			arr[len] = (tmp - 10) + 'A';
		n /= 16;
	}
	return (arr);
}
