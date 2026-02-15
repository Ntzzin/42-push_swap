# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/19 15:58:54 by nado-nas          #+#    #+#              #
#    Updated: 2026/02/15 18:46:49 by nado-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNAME = checker

CC = cc
INCLUDE = -Iincludes
CFLAGS = -Wall -Wextra -Werror

SRC = srcs/push_swap.c srcs/misc.c srcs/stack_utils.c srcs/ft_atoi.c srcs/a_ops.c srcs/b_ops.c srcs/calc_utils.c srcs/dbstack.c srcs/sort.c srcs/ft_strcmp.c srcs/lowest_cost.c srcs/r_to_top.c
BSRC = srcs/checker.c srcs/misc.c srcs/stack_utils.c srcs/ft_atoi.c srcs/a_ops.c srcs/b_ops.c srcs/dbstack.c srcs/ft_strcmp.c srcs/is_sorted.c
OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

PRINTF_PATH = ft_printf
MAKE_PRINTF = make -C $(PRINTF_PATH)
PRINTF = -L $(PRINTF_PATH) -lftprintf

GNL_PATH = get_next_line
MAKE_GNL = make -C $(GNL_PATH)
GNL = -L $(GNL_PATH) -lget_next_line

WORK_DIRS = ft_printf get_next_line includes srcs


all: check_norm $(NAME)

simple:
	@$(MAKE) CFLAGS="" $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(MAKE_PRINTF)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(PRINTF) -o $(NAME)

bonus: $(BOBJ)
	$(MAKE_PRINTF)
	$(MAKE_GNL)
	$(CC) $(CFLAGS) $(INCLUDE) $(BOBJ) $(PRINTF) $(GNL) -o $(BNAME)

check_norm:
	norminette $(WORK_DIRS)

clean:
	$(MAKE_PRINTF) clean
	$(MAKE_GNL) clean
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	$(MAKE_PRINTF) fclean
	$(MAKE_GNL) fclean
	rm -f $(NAME) $(BNAME)

re: fclean all

.PHONY: all bonus check_norm clean fclean re