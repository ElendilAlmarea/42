CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -I /usr/local/include -g -L /usr/local/lib -lmlx -l mlx -framework OpenGL -framework AppKit

NAME =		miniRT

SRC =		main.c \
			events.c \
			parser.c \
			usual_functions.c

$(NAME):
			${CC} ${CFLAGS} ${SRC} -o ${NAME}

all:		${NAME}

clean:
			rm -f ${NAME}
			rm -rf ${NAME}.dSYM

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re

temp:
			${CC} -I /usr/local/include -g -L /usr/local/lib -lmlx -l mlx -framework OpenGL -framework AppKit ${SRC} -o ${NAME} && ./${NAME}