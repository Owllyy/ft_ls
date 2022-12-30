#include "libft.h"

char	*ft_itoa(int nbr)
{
	char	*ret;
	int		neg;
	int		len;
	long	nb;

	nb = nbr;
	neg = nb < 0;
	len = ft_intlen(nb);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, len + 1);
	if (neg)
	{
		ret[0] = '-';
		nb = -nb;
	}
	while (len-- > neg)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (ret);
}
