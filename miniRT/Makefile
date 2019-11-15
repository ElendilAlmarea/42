CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -I /usr/local/include -g -L /usr/local/lib -lmlx -l mlx -framework OpenGL -framework AppKit

NAME =		miniRT

SRC =		main.c \
			events.c \
			parser.c \
			usual_functions.c \
			parse_calls1.c \
			parse_calls2.c \
			parse_funcs1.c \
			parse_funcs2.c \
			parse_funcs3.c \
			raytracer1.c \
			raytracer2.c \
			raytracer3.c

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