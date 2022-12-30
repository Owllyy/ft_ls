#include "libft.h"

size_t	ft_intlen(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}
