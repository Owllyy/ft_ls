#include "../includes/ft_ls.h"

int main(int ac, char **av) {
	(void)ac;
	t_ls ls;

	ls.list = 0;
	ls.pool = 0;
	av = parsing(av, &ls);
	ls.pool = init_pool(0, 4096);
	if (!ls.pool) {
		panic(ls.pool, "Pool initialization problem");
		return -1;
	}
	if (!*av) {
		init_list(&ls.list, ".", &ls);
		// sort_ls(&ls.list, &ls);
		display_files(&ls);
	}
	else {
		for (int i = 0; av[i]; i++) {
			init_list(&ls.list, av[i], &ls);
			// sort_ls(&ls.list, &ls);
			display_files(&ls);
		}
	}
}