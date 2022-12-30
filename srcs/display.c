#include "../includes/ft_ls.h"

void display_name(t_file * file) {
	ft_printf("%8s ", file->name);
}

static void display_basic(t_file * list) {
	for (t_file *i = list; i; i = i->next) {
		display_name(i);
	}
	printf("\n");
	for (t_file *i = list; i; i = i->next) {
		if (i->son)
			display_basic(i->son);
	}
}

static void display_list(t_file * list) {
	for (t_file *i = list; i; i = i->next) {
		display_permissions_type(i->mode);
		display_name(i);
		printf("\n");
	}
	printf("\n");
	for (t_file *i = list; i; i = i->next) {
		if (i->son)
			display_list(i->son);
	}
}

void display_files(t_ls *ls) {
	if (get_flag(ls->flags, l)) {
		display_list(ls->list);
	} else {
		display_basic(ls->list);
	}
}