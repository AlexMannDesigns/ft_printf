# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amann <amann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 12:30:40 by amann             #+#    #+#              #
#    Updated: 2022/03/09 16:25:28 by amann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#VARIABLES
NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror -ansi -pedantic -std=c99 -O3
LEAK_TEST = -g -fsanitize=address
LIB_DIR = libft/
LIBFT =  $(LIB_DIR)ft_atoi.c $(LIB_DIR)ft_bzero.c $(LIB_DIR)ft_isalnum.c		\
		$(LIB_DIR)ft_isalpha.c $(LIB_DIR)ft_isascii.c $(LIB_DIR)ft_isdigit.c	\
		$(LIB_DIR)ft_islower.c $(LIB_DIR)ft_lstiter.c $(LIB_DIR)ft_memcpy.c		\
		$(LIB_DIR)ft_memcmp.c $(LIB_DIR)ft_itoa.c $(LIB_DIR)ft_lstadd.c			\
		$(LIB_DIR)ft_lstdel.c $(LIB_DIR)ft_lstdelone.c $(LIB_DIR)ft_isprint.c	\
		$(LIB_DIR)ft_lstmap.c $(LIB_DIR)ft_lstnew.c $(LIB_DIR)ft_memalloc.c		\
		$(LIB_DIR)ft_memccpy.c $(LIB_DIR)ft_memchr.c $(LIB_DIR)ft_memdel.c		\
		$(LIB_DIR)ft_memmove.c $(LIB_DIR)ft_memset.c $(LIB_DIR)ft_putchar.c		\
		$(LIB_DIR)ft_putchar_fd.c $(LIB_DIR)ft_putendl.c $(LIB_DIR)ft_strcat.c	\
		$(LIB_DIR)ft_strequ.c $(LIB_DIR)ft_strmap.c $(LIB_DIR)ft_strmapi.c		\
		$(LIB_DIR)ft_putendl_fd.c $(LIB_DIR)ft_putnbr.c $(LIB_DIR)ft_putnbr_fd.c\
		$(LIB_DIR)ft_putstr.c $(LIB_DIR)ft_putstr_fd.c $(LIB_DIR)ft_strchr.c	\
		$(LIB_DIR)ft_strclr.c $(LIB_DIR)ft_strcmp.c	$(LIB_DIR)ft_strcpy.c		\
		$(LIB_DIR)ft_strdel.c $(LIB_DIR)ft_strdup.c	$(LIB_DIR)ft_striter.c		\
		$(LIB_DIR)ft_striteri.c $(LIB_DIR)ft_strjoin.c $(LIB_DIR)ft_strlcat.c	\
		$(LIB_DIR)ft_strlen.c $(LIB_DIR)ft_strncat.c $(LIB_DIR)ft_strncmp.c		\
		$(LIB_DIR)ft_strncpy.c $(LIB_DIR)ft_strnequ.c $(LIB_DIR)ft_strnew.c		\
		$(LIB_DIR)ft_strsplit.c $(LIB_DIR)ft_strstr.c $(LIB_DIR)ft_strsub.c		\
		$(LIB_DIR)ft_strtrim.c $(LIB_DIR)ft_tolower.c $(LIB_DIR)ft_freearray.c	\
		$(LIB_DIR)ft_iswhitespace.c $(LIB_DIR)ft_abs.c $(LIB_DIR)ft_strnstr.c	\
		$(LIB_DIR)ft_strrchr.c $(LIB_DIR)ft_toupper.c $(LIB_DIR)ft_isupper.c	\
		$(LIB_DIR)ft_lstadd_back.c $(LIB_DIR)ft_strndup.c
LIBFT_OBJ = $(LIBFT:.c=.o)
SRCS = conversion_control.c ft_printf.c	set_flags.c print_result.c hash_flag.c	\
		flag_control.c	numeric_conversion.c width_precision.c plus_flag.c		\
		ft_abs_long.c handle_double.c ft_printf_putstr.c double_helpers.c		\
		double_helpers2.c ft_itoa_base.c ft_itoa_base_unsigned.c				\
		signed_conversion_handlers.c unsigned_conversion_handlers.c add_sign.c	\
		n_conversion.c set_conv_type.c colours.c ft_printf_control.c			\
		chop_chop.c print_result_functions.c zero_flag.c
OBJ = $(SRCS:.c=.o)
TEST = tests_main.c
DOUBLE_TEST = double_test_main.c
ARC = $(LIB_DIR)libft.a

#RULES
all: $(NAME)

$(NAME):
	@@$(MAKE) -C $(LIB_DIR)
	@@gcc $(FLAGS) -c $(SRCS)
	@@ar rcs $(NAME) $(OBJ) $(LIBFT_OBJ)

clean:
	@@/bin/rm -f $(OBJ)
	@@make -C $(LIB_DIR) clean

fclean: clean
	@@/bin/rm -f $(NAME) test
	@@make -C $(LIB_DIR) fclean
	
re: fclean all 

#the below is just for testing with my main - creates a binary called test
test: $(NAME)
	gcc $(FLAGS) -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

float: $(NAME)
	gcc $(FLAGS) -o test $(DOUBLE_TEST) $(NAME) -I $(LIB_DIR) $(ARC)

#compiles the above tests, but will reveal any mem issues
leak_comp:
	@@$(MAKE) -C $(LIB_DIR)
	@@gcc $(FLAGS) $(LEAK_TEST) -c $(SRCS)
	@@ar rcs $(NAME) $(OBJ)

float_leak: leak_comp
	gcc $(FLAGS) $(LEAK_TEST) -o test $(DOUBLE_TEST) $(NAME) -I $(LIB_DIR) $(ARC)

test_leak: leak_comp
	gcc $(FLAGS) $(LEAK_TEST) -o test $(TEST) $(NAME) -I $(LIB_DIR) $(ARC)

.PHONY: all clean fclean re test float ref