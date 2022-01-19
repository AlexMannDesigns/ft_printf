/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/19 15:51:48 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
*	list of args and address of i needed to determine conversion and how far 
*	increment i process can effectively be split into two parts, one to handle
*	the flags, one for the conversion the conversion char will always be the 
*	last character we are interested in, so we can iterate until hitting this
*	then increment the i in printf by the number of characters read
*/

static char	*handle_conv(char *s, va_list lst, int *printf_i, t_flags flag_data)
{
	int		i;
	int		x;
	char	*res;

	i = 0;
	res = NULL;
	if (s[i] == 'd' || s[i] == 'i')
	{
		x = va_arg(lst, int);
		res = ft_itoa(x);
		ft_putstr(res);
	}
	return (res);
}

static void	ft_printf_helper(char *s, va_list lst, int *printf_i)
{
	int		i;
	t_flags	flag_data;
	char	*res;

	i = 0;
	while (!ft_isalpha(s[i]) || s[i] == 'h' || s[i] == 'l' || s[i] == 'L')
	{
		if (s[i] == '%')
		{
			ft_putchar('%');
			break ;
		}
		// else
		// 	handle_flags(s[i], &flag_data);
		i++;
	}
	res = handle_conv(s + i, lst, &i, flag_data);
	if (res)
		free(res);
	*printf_i += i + 1;
}

int	ft_printf(char *s, ...)
{
	va_list	lst;
	int		i;

	va_start(lst, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			ft_printf_helper(&s[i + 1],lst, &i);
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(lst);
	return (0);
}

int	main(void)
{
	// printf("this is a width test%10i!\n", 123);
	// printf("this is a precision & width test %10.5d\n", 123);
	// printf("\n3 + 4 + 5 + 6 = %d\n", add_numbers(4, 3, 4, 5, 6));
	unsigned int i = 5;

	unsigned int *ptr = &i;
	
	
	// printf("%10% hello%-10dhello\n", 69);
	// printf("%10% hello%10dhello\n", 69);
	printf("%d this is a test %c\n", 5, 'a');
	printf("print address of pointer with p: %p\n", ptr);
	printf("print address of pointer with x: %#lx\n", (long int)&i);
	printf("print a string with s: %s\n", "hello world");
	printf("print a string with s + precision: %.8s\n", "hello world");
	printf("print a character with c: %c\n", 65);
	printf("% d\n", 25);
	printf("% d\n", -25);
	printf("note with width set to '5', the sign is included\n");
	printf("%+05d\n", 25);
	printf("%+05d\n", -25);

	ft_printf("\n\nft_printf testing begins!!\n\n");
	ft_printf("hello %d world\n", 5);
	ft_printf("hello %%L% %%%% h.0 %%d world %d\n", 3, 2);
	//printf("hello %%L% %%%% h.0 %%d world %d\n", 3, 2);
	ft_printf("hello %hld world\n", 5);
	ft_printf("hello %hli world %i\n", 3, 2);
	return (0);
}
