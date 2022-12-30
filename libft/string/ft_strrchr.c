#include "../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (TRUE)
	{
		if (s[i] == (char)c)
			ret = (char *)(s + i);
		if (!s[i])
			break ;
		i++;
	}
	return (ret);
}
