# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 01:02:41 by mbrunel           #+#    #+#              #
#    Updated: 2020/03/08 14:56:13 by yvanat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell

BUILD=.build
D_SRC=src
D_INC=inc

D_OBJ=$(BUILD)/obj
D_DEP=$(BUILD)/dep
D_SUB=
DIRS:=$(D_DEP) $(addprefix $(D_DEP)/, $(D_SUB))\
	$(D_OBJ) $(addprefix $(D_OBJ)/, $(D_SUB))

GIT=$(D_LIBFT)/.git

D_LIB=lib
D_LIBFT=$(D_LIB)/libft
LIBFT=$(D_LIBFT)/libft.a

SUBMODULES=$(D_LIBFT)/.git

CC=gcc
CFLAGS=-Wall -Wextra -Ofast#-Werror
DFLAGS=-MP -MMD -MF $(D_DEP)/$*.d -MT $@
IFLAGS=-I$(D_INC) -I$(D_LIBFT)/inc
LDFLAGS= $(LIBFT) -Ofast

C_RED=\033[31m
C_GREEN=\033[32m
C_CYAN=\033[36m
C_NONE=\033[0m
BUILD_MSG=$(C_GREEN)\xE2\x9C\x94$(C_NONE)
REMOVE_MSG=$(C_RED)\xE2\x9C\x95$(C_NONE)

INC=$(D_INC)/minishell.h

SRC=main.c \
	builtins.c \
	lst.c args.c \
	parser1.c \
	parser2.c \
	parser3.c \
	parser4.c \
	parser5.c \
	launchs.c \
	std_utils.c \
	exec_path.c \
	pre_launch.c \
	env_handling.c \
	directories.c

OBJ:=$(patsubst %.c, $(D_OBJ)/%.o, $(SRC))
DEP:=$(patsubst %.c, $(D_DEP)/%.d, $(SRC))

all :
	@$(MAKE) -j $(NAME)

$(NAME) : $(GIT) $(OBJ)
	@$(MAKE) -C $(D_LIBFT)
	@$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)
	@printf "$(BUILD_MSG) %s\n" $@

clean :
	@rm -rf $(BUILD)
	@printf "$(REMOVE_MSG) rm %s\n" $(BUILD)

fclean : clean
	@rm -rf $(NAME)
	@printf "$(REMOVE_MSG) rm %s\n" $(NAME)
	@$(MAKE) -C $(D_LIBFT) fclean
	@printf "$(REMOVE_MSG) rm %s\n" $(LIBFT)

re : fclean all

$(BUILD) :
	@mkdir -p $@ $(DIRS)
	@printf "$(BUILD_MSG) %s\n" $@

$(GIT) :
	@git submodule init
	@git submodule update --remote

$(D_OBJ)/%.o : $(D_SRC)/%.c  Makefile | $(BUILD)
	@$(CC) $(CFLAGS) $(IFLAGS) $(DFLAGS) -c $< -o $@
	@printf "$(BUILD_MSG) %s\n" $<

-include $(DEP)

.PHONY: all clean fclean re
