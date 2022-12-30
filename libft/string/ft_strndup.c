#include "../libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*ret;

	ret = malloc(sizeof(char) * (n + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s[i] && i < n)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
