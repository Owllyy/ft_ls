#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*ret;

	i = 0;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]) + 1;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (start >= slen)
	{
		ft_bzero(ret, len + 1);
		return (ret);
	}
	while (i < len && s[start])
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
