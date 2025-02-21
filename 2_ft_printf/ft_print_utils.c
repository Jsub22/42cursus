/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:12:45 by subjeong          #+#    #+#             */
/*   Updated: 2024/12/17 20:21:47 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str)
{
	if (!str)
		return (write(1, "(null)", 6));
	return (write(1, str, ft_strlen(str)));
}

int	ft_print_dec(int n)
{
	char	*tmp;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	tmp = ft_itoa(n);
	len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	char	*tmp;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	tmp = ft_uitoa(n);
	len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

int	ft_print_hex(unsigned int n, char type)
{
	char	*tmp;
	int		len;

	if (n == 0)
		return (write(1, "0", 1));
	tmp = ft_uitoha((unsigned int)n, type);
	len = write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}

int	ft_print_ptr(void *ptr)
{
	char	*tmp;
	int		len;

	len = 0;
	if (!ptr)
		return (write(1, "(nil)", 5));
	len += (write(1, "0x", 2));
	tmp = ft_ptoa((uintptr_t)ptr);
	len += write(1, tmp, ft_strlen(tmp));
	free(tmp);
	return (len);
}
