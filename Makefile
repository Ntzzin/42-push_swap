# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 15:58:54 by nado-nas          #+#    #+#              #
#    Updated: 2026/02/06 16:46:07 by nado-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
INCLUDE = -Iincludes
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/main.c srcs/misc.c srcs/stack_utils.c srcs/ft_atoi.c srcs/a_ops.c srcs/b_ops.c srcs/calc_utils.c srcs/dbstack.c srcs/sort.c srcs/ft_strcmp.c srcs/others.c
OBJ = $(SRC:.c=.o)

PRINTF_PATH = ft_printf
MAKE_PRINTF = make -C $(PRINTF_PATH)
PRINTF = -L $(PRINTF_PATH) -lftprintf

WORK_DIRS = ft_printf includes srcs


all: check_norm $(NAME)

simple:
	@$(MAKE) CFLAGS="" $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(PRINTF) -o $(NAME)

check_norm:
	norminette $(WORK_DIRS)

clean:
	$(MAKE_PRINTF) clean
	rm -f $(OBJ)

fclean: clean
	$(MAKE_PRINTF) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all check_norm clean fclean re