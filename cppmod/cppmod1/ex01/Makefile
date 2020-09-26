NAME =		plomberie
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra

SRCS = 		${wildcard *.cpp}

all:		$(NAME)

$(NAME) :	
			$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :
			rm -f $(NAME)

fclean :	clean

re :		fclean all