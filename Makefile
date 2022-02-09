# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/02/09 13:41:55 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c99 -O3
SRCS = conversion_control.c ft_itoa_base.c ft_printf.c	set_flags.c 			\
		numeric_conversion.c width_precision.c 	print_result.c	flag_control.c	\
		hash_flag.c plus_flag.c ft_abs_long.c length_control.c handle_double.c
OBJ = $(SRCS:.c=.o)
TEST = tests_main.c
DOUBLE_TEST = double_test_main.c
LIB_DIR = libft/
ARC = $(LIB_DIR)libft.a

#RULES
all: $(NAME)

$(NAME):
	@@gcc $(FLAGS) -c $(SRCS)
	@@ar rcs $(NAME) $(OBJ)
	@@ranlib $(NAME)

#the below is just for testing with my main - spits out a binary called test
test: $(NAME)
	gcc $(FLAGS) -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

float: $(NAME)
	gcc $(FLAGS) -o test $(DOUBLE_TEST) $(NAME) -I $(LIB_DIR) $(ARC)

clean:
	@@/bin/rm -f $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME) a.out test

re: fclean test #remember to change this before submitting!!

ref: fclean float #remember to change this before submitting!!

.PHONY: all clean fclean re test float ref