#include "../libft.h"

t_flag		flag_init(void)
{
	t_flag	flag;

	flag.flag_large = 0;
	flag.flag_minus = 0;
	flag.flag_zero = 0;
	flag.flag_prec = -1;
	flag.flag_dot = 0;
	flag.to_i = 0;
	flag.minus_done = 0;
	return (flag);
}

int			ft_flagger(char *str, int *i, va_list va)
{
	t_flag	flag;

	flag = flag_init();
	while (str[++(*i)])
	{
		if ((str[*i] == '0' || str[*i] == '-') && !flag.flag_dot)
			ft_flag_zero_minus(str, i, &flag);
		else if (!(flag.flag_prec > -1) && str[*i] >= '0' && str[*i] <= '9')
			ft_large_prec(str, i, &flag);
		else if (!(flag.flag_prec > -1) && str[*i] == '*')
			ft_starlight(&flag, va);
		else if (flag.to_i > 0 || flag.flag_dot == 1)
		{
			(flag.flag_dot == 0) ? (flag.flag_large = flag.to_i) :
			(flag.flag_prec = flag.to_i);
			flag.to_i = 0;
			flag.flag_dot = 0;
			(*i)--;
		}
		else if (str[*i] == '.')
			flag.flag_dot = 1;
		else
			return (ft_eoflags(str, i, flag, va));
	}
	return (0);
}

int			ft_printf(const char *str, ...)
{
	int		i;
	va_list va;
	int		ret;
	int		check_ret;

	i = 0;
	ret = 0;
	va_start(va, str);
	while (str[i])
	{
		check_ret = 0;
		if (str[i] == '%')
			check_ret = ft_flagger((char*)str, &i, va);
		else
		{
			write(1, &(str[i]), 1);
			ret++;
		}
		if (check_ret == -1)
			return (-1);
		ret += check_ret;
		i++;
	}
	va_end(va);
	return (ret);
}
