/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subjeong <subjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 16:40:56 by subjeong          #+#    #+#             */
/*   Updated: 2025/03/15 23:14:22 by subjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int is_valid_num(char *s)
{
	long long int	ret;
	long long int	i;

	if (ft_strlen(s) == 0)
		return (-1);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s && s[i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i++]) == -1)
		{
			// ft_putstr_fd("a", 1);
			return (-1);
		}
	}
	ret = ft_atolli(s);
	if (ret < -2147483648 || ret > 2147483647)
	{
		// ft_putstr_fd("b", 1);
		return (-1);
	}
	else
		return (1);
}

static int is_valid_cmp(char *s1, char *s2)
{
	int	tmp;

	if (ft_strlen(s1) > ft_strlen(s2))
		return (1);
	else if (ft_strlen(s1) == ft_strlen(s2))
	{
		tmp = ft_strncmp(s1, s2, ft_strlen(s1));
		if (tmp == 0)
			return (-1);
		else if (tmp > 0)
			return (1);
	}
	return (0);
}

int	is_valid_args(int argc, char *argv[])
{
	int	i;
	int j;
	int tmp;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]) == -1)
			return (-1);
		i++;
	}
	i = 0;
	while (argv && argv[++i])
	{
		j = i;
		while (argv && argv[++j])
		{
			tmp = is_valid_cmp(argv[i], argv[j]);
			if (tmp == -1)
			{
				// ft_putstr_fd("c", 1);
				return (-1);
			}
		}
	}
	return (1);
}
