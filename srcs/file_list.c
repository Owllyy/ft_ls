#include "../includes/ft_ls.h"

t_file *add_file(t_file ** list, struct dirent * entity) {
	t_file *new_file;
	struct stat stat;

	new_file = malloc(sizeof(t_file));
	// if (!new_file)
	// 	fatal();
	new_file->name = strdup(entity->d_name);
	// if (!new_file->name)
	// 	fatal();
	lstat(new_file->name, &stat);
	new_file->mode = stat.st_mode;
	new_file->nlink = stat.st_nlink;
	new_file->uid = stat.st_uid;
	new_file->gid = stat.st_gid;
	new_file->size = stat.st_size;
	new_file->rdev = stat.st_rdev;
	new_file->time = stat.st_mtimespec.tv_sec;
	new_file->ntime = stat.st_mtimespec.tv_nsec;
	new_file->blocks = stat.st_blocks;
	// get_full_path(path, name, new->full_path);
	new_file->next = NULL;
	new_file->son = NULL;

	if (!*list) {
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

void init_list(t_file **list, char *path_name, t_ls *ls) {
	DIR * dir = opendir(path_name);
	struct dirent * entity;
	t_file *current_file;

	if (dir) {
		while ((entity = readdir(dir))) {
			current_file = add_file(list, entity);
			if (S_ISDIR(current_file->mode) && get_flag(ls->flags, R))
				init_list(&(current_file->son), current_file->name, ls);
		}
		closedir(dir);
	}
}