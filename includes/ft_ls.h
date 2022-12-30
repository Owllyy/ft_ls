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

#define PATH_MAX 4096

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
	l = 1,
	r = 2,
	R = 4,
	a = 8,
	t = 16
};

/*  ERRORS  */
void parsing_error(char c);

/*  PARSING  */
void options_parsing(char *flags, t_ls *ls);
char **parsing(char **av, t_ls *ls);

/*  DISPLAY  */
void display_files(t_ls *ls);
void display_name(t_file *file);
void display_permissions_type(mode_t mode);

/*  LIST  */
void init_list(t_file **list, char *path_name, t_ls *ls);

#endif