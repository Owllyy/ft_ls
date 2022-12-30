#include "../libft.h"

int			ft_prediction(long long n)
{
	int			size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char		*ft_puthex(unsigned long long ptr, char *base)
{
	char				*word;
	unsigned long long	save;
	int					len;

	len = 0;
	save = ptr;
	while (save)
	{
		save /= 16;
		len++;
	}
	if (ptr == 0)
		len++;
	if (!(word = malloc(len + 1)))
		return (0);
	word[len--] = 0;
	if (ptr == 0)
		word[0] = 48;
	while (ptr)
	{
		word[len--] = base[ptr % 16];
		ptr /= 16;
	}
	return (word);
}

int			ft_print_hexa(t_flag flag, va_list va, char maj)
{
	char			*str;
	int				ret;
	int				len;
	unsigned int	nbr;

	nbr = va_arg(va, unsigned int);
	if (maj == 'x')
		str = ft_puthex((unsigned long long)nbr, "0123456789abcdef");
	else
		str = ft_puthex((unsigned long long)nbr, "0123456789ABCDEF");
	if (!(len = ft_strlen(str)))
		return (-1);
	if (flag.flag_prec == 0 && !nbr)
		len = 0;
	if (!flag.flag_minus)
	{
		ret = ft_putlargenum(str, flag, len);
		ret += ft_putprecnum(str, flag, len);
		free(str);
		return (ret);
	}
	ret = ft_putprecnum(str, flag, len);
	ret += ft_putlargenum(str, flag, len);
	free(str);
	return (ret);
}
