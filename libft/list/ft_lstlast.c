#include "../libft.h"

t_list	*ft_lstlast(t_list *list)
{
	t_list	*next;

	next = list;
	if (!next)
		return (NULL);
	while (1)
	{
		if (!next->next)
			return (next);
		next = next->next;
	}
	return (NULL);
}
