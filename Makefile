# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/01/25 14:45:14 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS = conversion_control.c ft_itoa_base.c ft_printf.c	set_flags.c 			\
		numeric_conversion.c width_precision.c 	print_result.c	flag_control.c	\
		hash_flag.c
OBJ = $(SRCS:.c=.o)
TEST = tests.c
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
	gcc -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

clean:
	@@/bin/rm -f $(OBJ)

fclean: clean
	@@/bin/rm -f $(NAME) a.out test

re: fclean test #remember to change this before submitting!!

.PHONY: all clean fclean re test