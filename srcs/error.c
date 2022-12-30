#include "../includes/ft_ls.h"

void parsing_error(char c) {
	printf("ls: illegal option -- %c\nusage: ls [-Ralrt] [file ...]\n", c);
	exit(1);
}