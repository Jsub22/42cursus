#include "main.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

long long int	ft_atolli(const char *nptr)
{
	char			*ptr;
	int				i;
	long long int	sign;
	long long int	result;

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
		result = (result * 10) + sign * (long long int)(ptr[i] - '0');
		i++;
	}
	return (result);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr1[i] || ptr2[i]) && i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
