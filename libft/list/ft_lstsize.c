#include "../libft.h"

int	ft_lstsize(t_list *list)
{
	size_t	count;
	t_list	*next;

	count = 0;
	next = list;
	while (next)
	{
		next = next->next;
		count++;
	}
	return (count);
}
