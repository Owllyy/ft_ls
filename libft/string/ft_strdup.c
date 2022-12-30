#include "../libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	if (src)
	{
		ft_strlcpy(dest, (char *)src, ft_strlen(src) + 1);
	}
	return (dest);
}
