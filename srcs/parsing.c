#include "../includes/ft_ls.h"

void options_parsing(char *flags, t_ls *ls) {
	int i;

	i = 0;
	while (flags[i]) {
		switch (flags[i]) {
			case 't' : add_flag(ls->flags, t); break;
			case 'R' : add_flag(ls->flags, R); break;
			case 'l' : add_flag(ls->flags, l); break;
			case 'r' : add_flag(ls->flags, r); break;
			case 'a' : add_flag(ls->flags, a); break;
			default : parsing_error(flags[i]);
		}
		i++;
	}
}

int parsing(char **av, t_ls *ls) {

	if (av[1] && av[1][0] == '-' && av[1][1])
		options_parsing(&av[1][1], ls);
	return 0;
}