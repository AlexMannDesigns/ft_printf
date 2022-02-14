# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/02/14 16:22:43 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c99 -O3
SRCS = conversion_control.c ft_itoa_base.c ft_printf.c	set_flags.c 			\
		numeric_conversion.c width_precision.c 	print_result.c	flag_control.c	\
		hash_flag.c plus_flag.c ft_abs_long.c length_control.c handle_double.c	\
		handle_long_double.c ft_printf_putstr.c
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

clean:
	@@/bin/rm -f $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME)
	
re: fclean $(NAME) #remember to change this before submitting!!

#ref: fclean float #remember to change this before submitting!!

#the below is just for testing with my main - creates a binary called test
test: $(NAME)
	gcc $(FLAGS) -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

float: $(NAME)
	gcc $(FLAGS) -o test $(DOUBLE_TEST) $(NAME) -I $(LIB_DIR) $(ARC)

.PHONY: all clean fclean re test float ref