#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (TRUE)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		if (!s[i])
			break ;
		i++;
	}
	return (NULL);
}
