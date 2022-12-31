#include "../includes/ft_ls.h"

void get_full_path(char *old_path, char *name, char *new_path) {
	int i;

	for (i = 0; old_path[i]; i++) {
		new_path[i] = old_path[i];
	}
	new_path[i] = '/';
	i++;
	for (int j = 0; name[j]; j++) {
		new_path[i] = name[j];
		i++;
	}
	new_path[i] = 0;
}