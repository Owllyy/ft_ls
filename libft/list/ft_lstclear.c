#include "../libft.h"

void	ft_lstclear(t_list **list, void (*del)(void*))
{
	t_list	*swap;

	if (!list)
		return ;
	if (!*list)
		return ;
	if (!del)
		return ;
	while (*list)
	{
		swap = (*list)->next;
		(*del)((*list)->content);
		free(*list);
		*list = swap;
	}
}
