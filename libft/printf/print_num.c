#include "../libft.h"

int			ft_putprecnum(char *str, t_flag flag, int len)
{
	int i;
	int ret;

	i = 0 + flag.minus_done;
	ret = 0;
	if (str[i] == '-')
	{
		write(1, "-", 1);
		i++;
		ret++;
		len--;
	}
	while (len < flag.flag_prec && flag.flag_prec > -1)
	{
		write(1, "0", 1);
		flag.flag_prec--;
		ret++;
	}
	if (!((flag.flag_prec == 0) && *str == '0'))
	{
		write(1, &str[i], len);
		return (ret + len);
	}
	return (ret);
}

int			ft_putlargenum(char *str, t_flag flag, int len)
{
	int size;
	int ret;

	ret = 0;
	if (len < flag.flag_prec && flag.flag_prec > -1)
	{
		size = flag.flag_large - flag.flag_prec;
		if (*str == '-')
			size--;
	}
	else
		size = flag.flag_large - len;
	while (size > 0)
	{
		if (flag.flag_zero && flag.flag_prec < 0 && !flag.flag_minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		size--;
		ret++;
	}
	return (ret);
}

int			ft_print_int(t_flag flag, va_list va, int ret)
{
	char	*str;
	int		len;

	if (!(str = ft_itoa(va_arg(va, int))))
		return (-1);
	len = ft_strlen(str);
	(*str == '-' && flag.flag_prec == len) ? flag.flag_large-- : 0;
	if (flag.flag_zero && flag.flag_large && *str == '-' && flag.flag_prec < 0)
	{
		write(1, "-", 1);
		flag.minus_done = 1;
		flag.flag_large--;
	}
	if ((flag.flag_prec == 0) && *str == '0' && flag.flag_large)
		flag.flag_large++;
	if (!flag.flag_minus)
		ret += (ft_putlargenum(str, flag, len - flag.minus_done)
		+ ft_putprecnum(str, flag, len - flag.minus_done));
	else
		ret += (ft_putprecnum(str, flag, len - flag.minus_done) +
		ft_putlargenum(str, flag, len - flag.minus_done));
	free(str);
	return (ret + flag.minus_done);
}

int			ft_print_uint(t_flag flag, va_list va)
{
	char	*str;
	int		ret;
	int		len;

	if (!(str = ft_uitoa(va_arg(va, unsigned int))))
		return (-1);
	len = ft_strlen(str);
	if (flag.flag_prec == 0 && *str == '0')
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

int			ft_print_ptr(t_flag flag, va_list va)
{
	char	*str;
	int		ret;

	if (!(str = ft_puthex((unsigned long long)va_arg(va, void*)
		, "0123456789abcdef")))
		return (-1);
	if (!flag.flag_minus)
	{
		ret = ft_putlargenum(str, flag, ft_strlen(str) + 2);
		write(1, "0x", 2);
		ret += ft_putprecnum(str, flag, ft_strlen(str));
		free(str);
		return (ret + 2);
	}
	write(1, "0x", 2);
	ret = ft_putprecnum(str, flag, ft_strlen(str));
	ret += ft_putlargenum(str, flag, ft_strlen(str) + 2);
	free(str);
	return (ret + 2);
}
