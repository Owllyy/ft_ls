#include "../includes/ft_ls.h"

static unsigned int compare_assci(t_file * a, t_file * b) {
	return (strcmp(a->name, b->name));
}

static unsigned int compare_time(t_file * a, t_file * b) {
	return 0;
}

static t_file * swap_list_elem(t_file ** father, t_file * previous, t_file * a, t_file * b) {
	if (father) {
		*father = b;
		a->next = b->next;
		b->next = a;
	} else {
		previous->next = b;
		a->next = b->next;
		b->next = a;
	}
	return b;
}


//todo the swap need to change the cursor value
static void sort_list(t_file ** list, t_ls *ls) {
	t_file *previous;
	for (t_file * i = *list; i; i = i->next) {
		previous = *list;
		for (t_file * i = *list; i->next; i = i->next) {
			if (get_flag(ls->flags, t) && compare_time(i, i->next))
				i = i == *list ? swap_list_elem(list, previous, i, i->next) : swap_list_elem(NULL, previous, i, i->next);
			else if (get_flag(ls->flags, r) && compare_assci(i, i->next) < 0)
				i = i == *list ? swap_list_elem(list, previous, i, i->next) : swap_list_elem(NULL, previous, i, i->next);
			else if (compare_assci(i, i->next) > 0)
				i = i == *list ? swap_list_elem(list, previous, i, i->next) : swap_list_elem(NULL, previous, i, i->next);
			if (i != *list)
				previous = i;
		}
	}
}

void sort_ls(t_file ** list, t_ls *ls) {
	sort_list(list, ls);
	if (get_flag(ls->flags, R)) {
		for (t_file *i = *list; i; i = i->next) {
			if (i->son)
				sort_list(&(i->son), ls);
		}
	}
}