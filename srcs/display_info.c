#include "../includes/ft_ls.h"

void display_links(nlink_t links) {
	ft_printf("%2u ", (unsigned int)links);
}

void display_owner(struct passwd *pw) {
	ft_printf("%s ", pw->pw_name);
}

void display_group(struct passwd *pw) {
	struct group *gr = getgrgid(pw->pw_gid);
	// if (gr == NULL) {
	//   fatal();
	// }
	ft_printf(" %s ", gr->gr_name);
}

void display_size(off_t size) {
	ft_printf("%6u ", (unsigned int)size);
}

void display_date(time_t file_time) {
	time_t	now;
	char	*str_time;

	time(&now);
	str_time = ctime(&file_time);
	ft_printf("%.12s ", str_time + 4);
}