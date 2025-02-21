/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:47:53 by subjeong          #+#    #+#             */
/*   Updated: 2024/12/20 16:28:17 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

static int	parse_types(va_list *ap, char type)
{
	if (type == 'c')
		return (ft_print_char((char)va_arg(*ap, int)));
	else if (type == 's')
		return (ft_print_str(va_arg(*ap, char *)));
	else if (type == 'd' || type == 'i')
		return (ft_print_dec(va_arg(*ap, int)));
	else if (type == 'p')
		return (ft_print_ptr(va_arg(*ap, void *)));
	else if (type == 'u')
		return (ft_print_unsigned(va_arg(*ap, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(*ap, unsigned int), (char)type));
	else
		return (ft_print_char(type));
}

static int	parse(va_list *ap, char *format)
{
	int	tmp;
	int	count;
	int	i;

	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (i + 1 < (int)ft_strlen(format) \
			&& ft_strchr("csdipuxX%", format[i + 1]))
			{
				tmp = parse_types(ap, format[++i]);
				if (tmp == -1)
					return (-1);
				count += tmp;
			}
			else
				count += ft_print_char(format[i++]);
		}
		else
			count += ft_print_char(format[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = parse(&ap, (char *)format);
	if (count < 0)
		return (-1);
	va_end(ap);
	return (count);
}
