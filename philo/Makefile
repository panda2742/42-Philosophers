# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehosta <ehosta@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/15 18:04:28 by ehosta            #+#    #+#              #
#    Updated: 2025/03/11 10:40:29 by ehosta           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				:=	philo
MAKE_DIR			:=	.make/
override	DEPS	:=	$(patsubst %.o,%.d,$(OBJ))

override	BUILD_DIR	:=	$(MAKE_DIR)$(shell git branch --show-current)_philo/
override	SRC_DIR		:=	src/
override	SRCS		:=	life/philo_dies life/philo_eats life/philo_sleeps \
							life/philo_thinks locale/en locale/fr \
							locale/int_to_roman locale/names out/display_state \
							tools/ft_atoui tools/get_tv_diff clear_table \
							create_table main routine
override	SRC			:=	$(addprefix $(SRC_DIR),$(addsuffix .c,$(SRCS)))
override	OBJ			:=	$(patsubst $(SRC_DIR)%.c,$(BUILD_DIR)%.o,$(SRC))

override	DIRS	:=	$(sort $(dir $(NAME) $(OBJ) $(DEPS)))

LOCALE=0

CFLAGS		:=	-Wall -Wextra -Werror -MMD -MP -pthread -D LOCALE=$(LOCALE)
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
	norminette $(SRC_DIR) include/

.PHONY: compile
compile:
	@$(MAKE) all > /dev/null

.PHONY: run
run: compile
	./$(NAME) 3 800 200 200

-include $(DEPS)