#include "../libft.h"

int	is_to_find(const char *str, const char *to_find, size_t r)
{
	size_t	i;

	i = 0;
	if (r < ft_strlen(to_find))
		return (0);
	while (i < r && to_find[i])
	{
		if (to_find[i] != str[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;

	i = 0;
	if (!to_find)
		return ((char *)str);
	if (ft_strlen(str) < len)
		len = ft_strlen(str) + 1;
	while (i <= (int)len)
	{
		if (is_to_find(&str[i], to_find, len - i))
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
