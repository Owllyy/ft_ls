#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	result;
	int					sign;

	i = 0;
	result = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - 48);
		if (result >= INT_MAX && sign == -1)
			return (0);
		else if (result > INT_MAX && sign == 1)
			return (-1);
		i++;
	}
	return ((int)result * sign);
}
