#include "../libft.h"

int	ft_iswhitespace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
