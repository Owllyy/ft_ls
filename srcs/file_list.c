#include "../includes/ft_ls.h"

t_file *add_file(t_file ** list, struct dirent * entity, char * path, t_ls *ls) {
	t_file *new_file;
	struct stat stat;

	new_file = malloc_pool(sizeof(t_file), ls->pool);
	if (!new_file)
		panic(ls->pool, "Can't allocate new_file");

	new_file->name = malloc_pool(ft_strlen(entity->d_name), ls->pool);
	if (!new_file->name)
		panic(ls->pool, "Can't allocate new_file->name");
	new_file->name = ft_strdup(entity->d_name);

	get_full_path(path, new_file->name, new_file->full_path);
	lstat(new_file->full_path, &new_file->stat);
	new_file->pw = getpwuid(new_file->stat.st_uid);
	new_file->next = NULL;
	new_file->son = NULL;

	if (!(*list)) {
		*list = new_file;
	}
	else {
		for (t_file *i = *list; i; i = i->next) {
			if (!i->next) {
				i->next = new_file;
				break ;
			}
		}
	}
	return new_file;
}

int is_file_anonymous(char *file_name, t_ls *ls) {
	if (file_name[0] == '.') {
		if (!get_flag(ls->flags, a))
			return 0;
	}
	return 1;
}

int is_file(char *file_name) {
	if (file_name[0] == '.') {
		if (file_name[1] == 0)
			return 0;
		if (file_name[1] == '.' && file_name[2] == 0)
			return 0;
	}
	return 1;
}

void init_list(t_file **list, char *path_name, t_ls *ls) {
	DIR * dir;
	if (!path_name)
		dir = opendir(".");
	else
		dir = opendir(path_name);
	struct dirent * entity;
	t_file *current_file;

	if (dir) {
		while ((entity = readdir(dir))) {
			if (is_file_anonymous(entity->d_name, ls)) {
				current_file = add_file(list, entity, path_name, ls);
				if (S_ISDIR(current_file->stat.st_mode) && get_flag(ls->flags, R) && is_file(entity->d_name)) {
					init_list(&(current_file->son), current_file->full_path, ls);
				}
			}
		}
		closedir(dir);
	}
}
