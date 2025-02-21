#include "main.h"

static int is_valid_num(char *s)
{
	long long int	ret;
	long long int	i;

	if (ft_strlen(s) == 0)
		return (-1);
	i = 0;

	while (s && s[i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i++]) == 0)
			return (-1);
	}
	ret = ft_atolli(s);
	if (ret < -2147483648 || ret > 2147483647)
		return (-1);
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
		else
			return (0);
	}
	else
		return (0);
}

int	is_valid_args(int argc, char *argv[])
{
	int	i;
	int j;
	int	cnt;
	int tmp;

	i = 1;
	while (i < argc)
	{
		if (is_valid_num(argv[i]) == -1)
			return (-1);
		i++;
	}
	i = 0;
	cnt = 0;
	while (argv && argv[++i])
	{
		j = i;
		while (argv && argv[++j])
		{
			tmp = is_valid_cmp(argv[i], argv[j]);
			if (tmp == -1)
				return (-1);
			cnt += tmp;
		}
	}
	if (argc == 2 || cnt == 0)
		return (1);
	else
		return (1);
}
