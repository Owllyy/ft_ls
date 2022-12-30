#include "../libft.h"

void		ft_flag_zero_minus(char *str, int *i, t_flag *flag)
{
	if (str[*i] == '-')
	{
		(*flag).flag_minus = 1;
		(*flag).flag_zero = 0;
	}
	if (str[*i] == '0' && (*flag).flag_minus != 1)
		(*flag).flag_zero = 1;
}

void		ft_starlight(t_flag *flag, va_list va)
{
	(*flag).to_i = va_arg(va, int);
	if ((*flag).to_i < 0 && !(*flag).flag_dot)
	{
		(*flag).flag_minus = 1;
		(*flag).to_i *= -1;
	}
}

void		ft_large_prec(char *str, int *i, t_flag *flag)
{
	while (str[*i] >= '0' && str[*i] <= '9' && (*flag).flag_prec == -1)
	{
		flag->to_i = flag->to_i * 10 + str[*i] - '0';
		(*i)++;
	}
	(*i)--;
}

int			ft_eoflags(char *str, int *i, t_flag flag, va_list va)
{
	if (str[*i] == 'c')
		return (ft_print_char(flag, va));
	else if (str[*i] == 's')
		return (ft_print_str(flag, va));
	else if (str[*i] == 'p')
		return (ft_print_ptr(flag, va));
	else if (str[*i] == 'd' || str[*i] == 'i')
		return (ft_print_int(flag, va, 0));
	else if (str[*i] == 'u')
		return (ft_print_uint(flag, va));
	else if (str[*i] == 'x' || str[*i] == 'X')
		return (ft_print_hexa(flag, va, str[*i]));
	else if (str[*i] == '%')
		return (ft_print_perc(flag));
	return (-1);
}
