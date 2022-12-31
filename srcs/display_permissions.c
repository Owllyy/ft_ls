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

//todo
static char get_acl_flag(mode_t mode, char *file_path) {
	acl_t	tmp;
	char	buf[101];

	if (listxattr(file_path, buf, sizeof(buf), XATTR_NOFOLLOW) > 0)
		return ('@');
	if ((tmp = acl_get_link_np(file_path, ACL_TYPE_EXTENDED)))
	{
		acl_free(tmp);
		return ('+');
	}
	return (' ');
}

void display_permissions_type(mode_t mode, char *file_path) {
	char perms[12];

	perms[0] = get_type(mode);

	//set user permissions + SUID char
	perms[1] = get_flag(mode, S_IRUSR) ? 'r': '-';
	perms[2] = get_flag(mode, S_IWUSR) ? 'w': '-';
	perms[3] = get_flag(mode, S_IXUSR) ? 'x': '-';
		perms[3] = get_flag(mode, S_ISUID) ? (perms[3] == '-' ? 'S' : 's') : perms[3];
	//set group permissions + GUID char
	perms[4] = get_flag(mode, S_IRGRP) ? 'r': '-';
	perms[5] = get_flag(mode, S_IWGRP) ? 'w': '-';
	perms[6] = get_flag(mode, S_IXGRP) ? 'x': '-';
		perms[6] = get_flag(mode, S_ISGID) ? (perms[6] == '-' ? 'S' : 's') : perms[6];
	//set other permissions + SVTX char
	perms[7] = get_flag(mode, S_IROTH) ? 'r': '-';
	perms[8] = get_flag(mode, S_IWOTH) ? 'w': '-';
	perms[9] = get_flag(mode, S_IXOTH) ? 'x': '-';
		perms[9] = get_flag(mode, S_ISVTX) ? (perms[9] == '-' ? 'T' : 't') : perms[9];
	
	perms[10] = get_acl_flag(mode, file_path);
	perms[11] = 0;
	ft_printf("%s ", perms);
}