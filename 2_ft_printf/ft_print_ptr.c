/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:13:50 by subjeong          #+#    #+#             */
/*   Updated: 2024/12/13 18:39:46 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_ptr_len(uintptr_t n)
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

char	*ft_ptoa(uintptr_t n)
{
	char			*arr;
	int				len;
	unsigned int	tmp;

	len = ft_ptr_len(n);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	arr[len] = '\0';
	while (--len >= 0)
	{
		tmp = n % 16;
		if (tmp < 10)
			arr[len] = tmp + '0';
		else
			arr[len] = (tmp - 10) + 'a';
		n /= 16;
	}
	return (arr);
}
