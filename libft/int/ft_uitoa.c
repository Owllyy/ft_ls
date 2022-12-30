#include "../libft.h"

char	*ft_uitoa(unsigned long long nbr)
{
	char	*ret;
	int		len;
	long	nb;

	nb = nbr;
	len = ft_intlen(nb);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	ft_bzero(ret, len + 1);
	while (len--)
	{
		ret[len] = nb % 10 + 48;
		nb /= 10;
	}
	return (ret);
}
