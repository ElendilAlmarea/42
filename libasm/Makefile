SRC_DIR = 	srcs
OBJ_DIR = 	objs
ASMC =		nasm
ASMFLAGS =	-fmacho64
CC = 		gcc
CFLAGS = 	-Wall -Werror -Wall
NAME =		libasm.a

SRC =			ft_strcpy.s\
				ft_strlen.s\
				ft_strcmp.s\
				ft_write.s\
				ft_read.s\
				ft_strdup.s\

OBJ =			$(patsubst %.s, $(OBJ_DIR)/%.o, $(SRC))

$(NAME): $(OBJ)				
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)
				$(ASMC) $(ASMFLAGS) main.s
				ld -macosx_version_min 10.7.0 -lSystem main.o libasm.a && ./a.out

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.s Makefile
				mkdir -p $(OBJ_DIR)
				$(ASMC) $(ASMFLAGS) $< -o $@

all: $(NAME)

clean:
				rm -f $(OBJ)

fclean: clean
				rm -f $(NAME) a.out main.o

re:	fclean all