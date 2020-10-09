NAME =		zombie
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra

SRCS = 		${wildcard *.cpp}

all:		$(NAME)

$(NAME) :
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

run: 		$(NAME)
			./$(NAME)

clean :
			rm -f $(NAME)

fclean :	clean

re :		fclean all