# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/29 14:14:15 by nado-nas          #+#    #+#              #
#    Updated: 2026/01/29 14:15:04 by nado-nas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
INCLUDE= -I../includes
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c ft_putbasen.c ft_putcharn.c ft_putstrn.c

OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	ar rcs $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
