#include "../libft.h"

size_t	ft_uintlen(unsigned long long nbr, int baselen)
{
	size_t	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr /= baselen;
		i++;
	}
	return (i);
}
