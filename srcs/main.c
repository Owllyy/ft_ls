#include "../includes/ft_ls.h"

int main(int ac, char **av) {
	(void)ac;
	t_ls ls;
	struct stat test;
	struct stat testo;
	struct stat testi;
	parsing(av, &ls);

	stat("libft", &test);
	test.
	display_permissions_type(test.st_mode);
}