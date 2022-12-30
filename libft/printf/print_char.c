#include "../libft.h"

int			ft_putprec(char *str, t_flag flag, int len)
{
	if (flag.flag_prec == 0)
		return (0);
	if (len > flag.flag_prec && flag.flag_prec > -1)
	{
		write(1, str, flag.flag_prec);
		return (flag.flag_prec);
	}
	write(1, str, len);
	return (len);
}

int			ft_putlarge(t_flag flag, int len)
{
	int size;
	int ret;

	ret = 0;
	if (len > flag.flag_prec && flag.flag_prec > -1)
		size = flag.flag_large - flag.flag_prec;
	else
		size = flag.flag_large - len;
	while (size > 0)
	{
		if (flag.flag_zero && !flag.flag_minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		size--;
		ret++;
	}
	return (ret);
}

int			ft_print_perc(t_flag flag)
{
	int ret;

	if (!flag.flag_minus)
	{
		ret = ft_putlarge(flag, 1) + 1;
		write(1, "%", 1);
		return (ret);
	}
	write(1, "%", 1);
	ret = ft_putlarge(flag, 1) + 1;
	return (ret);
}

int			ft_print_char(t_flag flag, va_list va)
{
	char	c;
	int		ret;

	c = va_arg(va, int);
	if (!flag.flag_minus)
	{
		ret = ft_putlarge(flag, 1) + 1;
		write(1, &c, 1);
		return (ret);
	}
	write(1, &c, 1);
	ret = ft_putlarge(flag, 1) + 1;
	return (ret);
}

int			ft_print_str(t_flag flag, va_list va)
{
	char	*str;
	int		ret;

	str = va_arg(va, char*);
	if (!str)
		str = "(null)";
	if (!flag.flag_minus)
	{
		ret = ft_putlarge(flag, ft_strlen(str));
		ret += ft_putprec(str, flag, ft_strlen(str));
		return (ret);
	}
	ret = ft_putprec(str, flag, ft_strlen(str));
	ret += ft_putlarge(flag, ft_strlen(str));
	return (ret);
}
