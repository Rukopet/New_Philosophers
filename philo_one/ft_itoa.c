#include "philo.h"

static char	*mem(int len)
{
	char			*alloc;

	alloc = malloc(sizeof(char) * (len + 1));
	if (NULL == alloc)
		return (NULL);
	return (alloc);
}

static char	*ft_positive_num(int n, int len)
{
	char			*str;

	str = mem(len);
	if (!str)
		return (NULL);
	else
	{
		str[len] = '\0';
		len--;
		while (len >= 0)
		{
			str[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (str);
	}
	return (NULL);
}

static char	*ft_negative_num(int n, int len)
{
	char			*str;

	str = mem(len + 1);
	if (!str)
		return (NULL);
	else
	{
		len++;
		str[len] = '\0';
		len--;
		str[0] = '-';
		while (len > 0)
		{
			str[len] = ((n % 10) + '0');
			n = n / 10;
			len--;
		}
		return (str);
	}
	return (NULL);
}

int	get_capacity(int n)
{
	int				ret;
	int				rank;

	ret = 0;
	rank = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / rank;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = get_capacity(n);
	if (n >= 0)
	{
		str = ft_positive_num(n, len);
		if (!str)
			return (NULL);
		else
			return (str);
	}
	else
	{
		str = ft_negative_num(-n, len);
		if (!str)
			return (NULL);
		else
			return (str);
	}
	return (NULL);
}
