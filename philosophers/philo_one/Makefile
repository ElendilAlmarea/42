# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/27 06:20:58 by mbrunel           #+#    #+#              #
#    Updated: 2021/01/18 17:02:25 by yvanat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo_one

CC=clang
CFLAGS=-Wall -Wextra -Werror -g3
IFLAGS=-I$(D_INC)
LDFLAGS=
LDLIBS=-lpthread
DFLAGS=-MP -MMD -MF $(D_DEP)/$*.d -MT $@
CPPFLAGS=$(IFLAGS) $(DFLAGS) $(CFLAGS)

C_RED=\033[31m
C_GREEN=\033[32m
C_CYAN=\033[36m
C_NONE=\033[0m
CROSS=✘
CHECK=✔
BUILD_MSG=$(C_GREEN)$(CHECK)$(C_NONE)
REMOVE_MSG=$(C_RED)$(CROSS)$(C_NONE)

D_SRC=src
D_INC=inc
BUILD=.build
D_OBJ=$(BUILD)/obj
D_DEP=$(BUILD)/dep
D_SUB=
DIRS:=$(BUILD) $(D_DEP)  $(addprefix $(D_DEP)/, $(D_SUB))\
				$(D_OBJ) $(addprefix $(D_OBJ)/, $(D_SUB))

SRC=main.c\
	utils.c\
	utils2.c\
	philosophers.c\

OBJ:=$(patsubst %.c, $(D_OBJ)/%.o, $(SRC))
DEP:=$(patsubst %.c, $(D_DEP)/%.d, $(SRC))

all :
		@$(MAKE) -s $(NAME)

$(NAME) : $(OBJ)
		@$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
		@printf "$(BUILD_MSG) %s\n" $@

-include $(DEP)

$(D_OBJ)/%.o : $(D_SRC)/%.c | $(DIRS)
		@$(CC) $(CPPFLAGS) -o $@ -c $<
		@printf "$(BUILD_MSG) %s\n" $(<F)

$(DIRS) :
		@mkdir -p $@

clean :
		@printf "$(REMOVE_MSG) %s\n" $(D_OBJ)
		@rm -rf $(D_OBJ)

fclean :
		@printf "$(REMOVE_MSG) %s\n" $(NAME) $(BUILD)
		@rm -rf $(NAME) $(BUILD)

re : clean all
