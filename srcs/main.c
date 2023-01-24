#include "../includes/ft_ls.h"

int main(int ac, char **av) {
	(void)ac;
	t_ls ls;
	av = parsing(av, &ls);
	for (int i = 0; av[i]; i++) {
		init_list(&ls.list, av[i], &ls);
		sort_ls(&ls.list, &ls);
		display_files(&ls);
	}
}

// int main(ac, av) {
// 	 error;
// 	Config config = config_new(av, &error);
// 	if (error) {
// 		handle_error();
// 	}
// 	run(config, &error);
// 	config_destroy(&config);
// }