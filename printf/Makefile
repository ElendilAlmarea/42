CC =		gcc

CFLAGS =	-Wall -Werror -Wextra -I.

NAME =		libftprintf.a

SRC =	ft_printf.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf_utils3.c \
			ft_printf_utils4.c \
			ft_printf_utils5.c \

OBJ =		${SRC:%.c=%.o}

$(NAME):
			${CC} ${CFLAGS} -c ${SRC}
			ar rc ${NAME} ${OBJ}
			ranlib ${NAME}

all:		${NAME}

clean:
			rm -f ${OBJ}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
