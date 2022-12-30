#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*array;
	size_t	total;

	total = count * size;
	array = malloc(total);
	if (!array)
		return (NULL);
	ft_memset(array, 0, total);
	return (array);
}
