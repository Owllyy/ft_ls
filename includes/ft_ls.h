# ifndef FT_LS_H
#define FT_LS_H

#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <grp.h>
#include <uuid/uuid.h>
#include <sys/xattr.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <sys/acl.h>
#include "../libft/libft.h"

typedef struct			s_file
{
	blkcnt_t			blocks;
	mode_t				mode;
	nlink_t				nlink;
	uid_t				uid;
	gid_t				gid;
	off_t				size;
	dev_t				rdev;
	time_t				time;
	long				ntime;
	struct passwd		*pw;
	char				*name;
	char				full_path[PATH_MAX];
	struct s_file		*next;
	struct s_file		*son;
}						t_file;

typedef struct s_ls
{
	char flags;
	t_file *list;
} t_ls;

/*  OPTIONS TOOLS  */
#define add_flag(a, b)       (a = a | b)
#define get_flag(a, b)       ((a & b) ? 1 : 0)
enum options {
	l = 1 << 0,
	r = 1 << 1,
	R = 1 << 2,
	a = 1 << 3,
	t = 1 << 4,
};

/*  ERRORS  */
void parsing_error(char c);

/*  PARSING  */
void options_parsing(char *flags, t_ls *ls);
char **parsing(char **av, t_ls *ls);

/*  DISPLAY  */
void display_files(t_ls *ls);
void display_name(t_file *file);
void display_permissions_type(mode_t mode, char *file_path);
void display_links(nlink_t links);
void display_owner(struct passwd *pw);
void display_group(struct passwd *pw);
void display_size(off_t size);
void display_date(time_t file_time);

/*  LIST  */
void init_list(t_file **list, char *path_name, t_ls *ls);
void sort_ls(t_file ** list, t_ls *ls);

/*  PATH  */
void get_full_path(char *old_path, char *name, char *new_path);

#endif