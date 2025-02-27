/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:09:36 by subjeong          #+#    #+#             */
/*   Updated: 2025/02/22 18:27:29 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	int len;

	if (!s || fd < 0)
		return ;
	len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

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

int	ft_atoi(const char *nptr)
{
	char	*ptr;
	int		i;
	int		sign;
	int		result;

	ptr = (char *)nptr;
	i = 0;
	sign = 1;
	result = 0;
	while ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == 32)
		i++;
	if (ptr[i] == '+' || ptr[i] == '-')
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] >= '0' && ptr[i] <= '9')
	{
		result = (result * 10) + sign * (ptr[i] - '0');
		i++;
	}
	return (result);
}