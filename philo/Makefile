# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/03/06 15:53:17 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo
MAKE_DIR			:=	.make/
override	DEPS	:=	$(patsubst %.o,%.d,$(OBJ))

override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)_philo/
override	SRC_DIR		:=	src/
override	SRCS		:=	life main out table time tools
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))
override	ASM_OBJ		:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.s,$(SRC))

override	DIRS	:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP -pthread
ASMFLAGS	:=	$(CFLAGS) -S
MAKEFLAGS	:=	--no-print-directory
RMFLAGS		:=	-rf
override	GCC		:=	cc
override	RM		:=	rm

.PHONY: all
all:	$(NAME)

$(NAME): $(OBJ) include/philo.h Makefile
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BUILD_DIR)%.o: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(CFLAGS) -Iinclude/ -c $< -o $@

.PHONY: asm
asm: $(ASM_OBJ) $(OBJ) philo.h Makefile
	$(MAKE)

$(BUILD_DIR)%.s: $(SRC_DIR)%.c | $(DIRS)
	$(CC) $(ASMFLAGS) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(RMFLAGS) $(BUILD_DIR)

.PHONY: fclean
fclean:	clean
	$(RM) $(RMFLAGS) $(NAME) $(MAKE_DIR)

.PHONY: re
re:		fclean
	$(MAKE)

$(DIRS):
	@mkdir -p $@

.PHONY: norm
norm:
	norminette $(SRC_DIR) include/ libft/

.PHONY: compile
compile:
	@$(MAKE) all > /dev/null

.PHONY: run
run: compile
	./$(NAME) 3 2000 200 200 2

-include $(DEPS)