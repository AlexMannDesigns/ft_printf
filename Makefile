# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/02/16 15:48:59 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c99 -O3
LEAK_TEST = -g -fsanitize=address
SRCS = conversion_control.c ft_itoa_base.c ft_printf.c	set_flags.c 			\
		numeric_conversion.c width_precision.c 	print_result.c	flag_control.c	\
		hash_flag.c plus_flag.c ft_abs_long.c length_control.c handle_double.c	\
		ft_printf_putstr.c double_helpers.c
OBJ = $(SRCS:.c=.o)
TEST = tests_main.c
DOUBLE_TEST = double_test_main.c
LIB_DIR = libft/
ARC = $(LIB_DIR)libft.a

#RULES
all:
	@@$(MAKE) -C $(LIB_DIR)
	@@$(MAKE) $(NAME)

$(NAME):
	@@gcc $(FLAGS) -c $(SRCS)
	@@ar rcs $(NAME) $(OBJ)

clean:
	@@/bin/rm -f $(OBJ)
	@@make -C $(LIB_DIR) clean

fclean: clean
	@@/bin/rm -f $(NAME) test
	@@make -C $(LIB_DIR) fclean
	
re: fclean all #remember to change this before submitting!!

#ref: fclean float #remember to change this before submitting!!

#the below is just for testing with my main - creates a binary called test
test: $(NAME)
	gcc $(FLAGS) -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

float: $(NAME)
	gcc $(FLAGS) -o test $(DOUBLE_TEST) $(NAME) -I $(LIB_DIR) $(ARC)

.PHONY: all clean fclean re test float ref