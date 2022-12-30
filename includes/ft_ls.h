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
}						t_file;

typedef struct s_ls
{
	char flags;

} t_ls;

/*  PERMISSIONS FLAG DEFINE */
#define S_IRWXU 0000700    /* RWX mask for owner */
#define S_IRUSR 0000400    /* R for owner */
#define S_IWUSR 0000200    /* W for owner */
#define S_IXUSR 0000100    /* X for owner */

#define S_IRWXG 0000070    /* RWX mask for group */
#define S_IRGRP 0000040    /* R for group */
#define S_IWGRP 0000020    /* W for group */
#define S_IXGRP 0000010    /* X for group */

#define S_IRWXO 0000007    /* RWX mask for other */
#define S_IROTH 0000004    /* R for other */
#define S_IWOTH 0000002    /* W for other */
#define S_IXOTH 0000001    /* X for other */

#define S_ISUID 0004000    /* set user id on execution */
#define S_ISGID 0002000    /* set group id on execution */
#define S_ISVTX 0001000    /* save swapped text even after use */

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
int parsing(char **av, t_ls *ls);

/*  DISPLAY  */
void display_permissions_type(mode_t mode);

#endif