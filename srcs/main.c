#include "../includes/ft_ls.h"

int main(int ac, char **av) {
	(void)ac;
	t_ls ls;
	av = parsing(av, &ls);
	for (int i = 0; av[i]; i++) {
		if ((ac > 2 && !ls.flags) || ac > 3)
			printf("%s:\n", av[i]);
		init_list(&ls.list, av[i], &ls);
		display_files(&ls);
	}
}