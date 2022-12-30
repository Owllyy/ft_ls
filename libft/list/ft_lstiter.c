#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*next;

	if (!lst)
		return ;
	next = lst;
	while (TRUE)
	{
		(*f)(next->content);
		next = next->next;
		if (!next)
			return ;
	}
}
