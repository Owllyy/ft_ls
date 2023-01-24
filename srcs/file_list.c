#include "../includes/ft_ls.h"

t_file *add_file(t_file ** list, struct dirent * entity, char * path) {
	t_file *new_file;
	struct stat stat;

	new_file = malloc(sizeof(t_file));
	// if (!new_file)
	// 	fatal();
	new_file->name = ft_strdup(entity->d_name);
	// if (!new_file->name)
	// 	fatal();
	get_full_path(path, new_file->name, new_file->full_path);
	lstat(new_file->full_path, &stat);
	new_file->mode = stat.st_mode;
	new_file->nlink = stat.st_nlink;
	new_file->uid = stat.st_uid;
	new_file->gid = stat.st_gid;
	new_file->size = stat.st_size;
	new_file->rdev = stat.st_rdev;
	new_file->time = stat.st_mtimespec.tv_sec;
	new_file->ntime = stat.st_mtimespec.tv_nsec;
	new_file->blocks = stat.st_blocks;
	new_file->pw = getpwuid(new_file->uid);
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
			if (entity->d_name[0] != '.' || get_flag(ls->flags, a)) {
				current_file = add_file(list, entity, path_name);
				if (S_ISDIR(current_file->mode) && get_flag(ls->flags, R)) {
					init_list(&(current_file->son), current_file->full_path, ls);
				}
			}
		}
		closedir(dir);
	}
}

// void init_list2(t_file **list, char *path_name, t_ls *ls) {
// 	DIR * dir = opendir(path_name);
// 	struct dirent * entity;
// 	t_file *current_file;

// 	if (!dir) return;

// 	while ((entity = readdir(dir))) {
// 		if (entity->d_name[0] == '.' && !get_flag(ls->flags, a))
// 			continue;

// 		current_file = add_file(list, entity, path_name);
// 		if (S_ISDIR(current_file->mode) && get_flag(ls->flags, R)) {
// 			init_list(&(current_file->son), current_file->full_path, ls);
// 		}
// 	}
// 	closedir(dir);
// }

// struct DirEntry {
// 	enum Type {
// 		Dir,
// 		File,
// 	};
// 	union {
// 		Dir dir;
// 		File file;
// 	};
// };

// struct DirEntryList {
// 	DirEntry* start;
// 	DirEntry* end;
// };

// struct Dir {
// 	DirInfo info;
// 	DirEntryList entries;
// };

// struct File {
// 	FileInfo info;
// };

// Result Dir_init(Dir* dir, Path path);

// Result DirEntryList_push(DirEntryList* list, DirEntry entry);
