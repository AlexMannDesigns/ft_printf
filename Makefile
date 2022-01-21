# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/01/21 13:05:57 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = conversion_control.c ft_itoa_base.c ft_printf.c	set_flags.c 			\
		numeric_conversion.c #flag_control.c (WIP)
OBJ = $(SRCS:.c=.o)
TEST = tests.c
LIB_DIR = libft/

#RULES
all: $(NAME)

$(NAME):
	@@gcc $(FLAGS) -c $(SRCS)
	@@ar rcs $(NAME) $(OBJ)
	@@ranlib $(NAME)

test: $(NAME)
	gcc $(FLAGS) $(TEST) $(NAME) -o test

clean:
	@@/bin/rm -f $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME) a.out test

re: fclean test #remember to change this before submitting!!

.PHONY: all clean fclean re test