SRC		=	parsing.c \
			error.c \
			display.c \
			display_info.c \
			display_permissions.c \
			file_list.c \
			get_path.c \
			sort_list.c \
			main.c

SRCS 	=	$(addprefix srcs/, ${SRC})

OBJS	=	${SRCS:.c=.o}

INCS	=	includes

NAME	=	ft_ls

LIBC	=	ar rcs

CC		=	gcc

RM		=	rm -f

CFLAGS	=	#-Wall -Wextra -Werror -g3


srcs/%.o: srcs/%.c ${INCS}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCS} -g

${NAME}: ${OBJS}
	@${MAKE} bonus -C ./libft
	${CC} -o ${NAME} ${OBJS} libft/libft.a

all: ${NAME}

bonus: all

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}
	${RM} a.out

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re .c.o