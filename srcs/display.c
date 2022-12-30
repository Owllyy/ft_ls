#include "../includes/ft_ls.h"

static char get_type(mode_t mode) {
	if (S_ISREG(mode))
		return ('-');
	else if (S_ISDIR(mode))
		return ('d');
	else if (S_ISLNK(mode))
		return ('l');
	else if (S_ISBLK(mode))
		return ('b');
	else if (S_ISCHR(mode))
		return ('c');
	else if (S_ISSOCK(mode))
		return ('s');
	else if (S_ISFIFO(mode))
		return ('p');
	else
		return ('-');
}

void display_permissions_type(mode_t mode) {
	char perms[12];

	perms[0] = get_type(mode);
	perms[1] = get_flag(mode, S_IRUSR) ? 'r': '-';
	perms[2] = get_flag(mode, S_IWUSR) ? 'w': '-';
	perms[3] = get_flag(mode, S_IXUSR) ? 'x': '-';
	perms[4] = get_flag(mode, S_IRGRP) ? 'r': '-';
	perms[5] = get_flag(mode, S_IWGRP) ? 'w': '-';
	perms[6] = get_flag(mode, S_IXGRP) ? 'x': '-';
	perms[7] = get_flag(mode, S_IROTH) ? 'r': '-';
	perms[8] = get_flag(mode, S_IWOTH) ? 'w': '-';
	perms[9] = get_flag(mode, S_IXOTH) ? 'x': '-';
	perms[10] = ' ';
	perms[11] = 0;
	printf("%s\n", perms);
}