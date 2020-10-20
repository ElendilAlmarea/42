NAME =		replace
CC =		clang++
CFLAGS =	-Wall -Werror -Wextra

SRCS = 		${wildcard *.cpp}
OBJ =		$(SRCS:.cpp=.o)

all:		$(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $@ -c $<

$(NAME) :	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

run: 		$(NAME)
			./$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all