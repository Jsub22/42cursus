/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:31:40 by subjeong          #+#    #+#             */
/*   Updated: 2024/10/22 15:36:30 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive(int n, int fd, int sign)
{
	if (n != 0)
	{
		recursive(n / 10, fd, sign);
		ft_putchar_fd((n % 10) * sign + '0', fd);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	sign;

	if (fd < 0)
		return ;
	sign = -1;
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		else
			sign = 1;
		recursive(n, fd, sign);
	}
}
