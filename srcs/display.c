#include "../includes/ft_ls.h"

void display_name(t_file * file) {
	ft_printf("%s ", file->name);
}

static void display_basic(t_file * list) {
	for (t_file *i = list; i; i = i->next) {
		display_name(i);
	}
	ft_printf("\n\n");
	for (t_file *i = list; i; i = i->next) {
		if (i->son) {
			ft_printf("%s: \n", i->full_path);
			display_basic(i->son);
			ft_printf("\n");
		}
	}
}

static void display_block(t_file * list) {
	long long total = 0;
	for (t_file *i = list; i; i = i->next) {
		total += (long long)i->blocks;
	}
	ft_printf("total %d\n", (int)total);
}

static void display_list(t_file * list) {
	display_block(list);
	for (t_file *i = list; i; i = i->next) {
		display_permissions_type(i->stat.st_mode, i->full_path);
		display_links(i->stat.st_nlink);
		display_owner(i->pw);
		display_group(i->pw);
		display_size(i->stat.st_size);
		display_date(i->stat.st_mtimespec.tv_sec);
		display_name(i);
		ft_printf("\n");
	}
	for (t_file *i = list; i; i = i->next) {
		if (i->son) {
			ft_printf("\n%s: \n", i->full_path);
			display_list(i->son);
		}
	}
}

void display_files(t_ls *ls) {
	if (get_flag(ls->flags, l)) {
		display_list(ls->list);
	} else {
		display_basic(ls->list);
	}
}