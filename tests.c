/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 09:30:31 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 09:30:31 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	basic testing:
*		- basic output of char, string and mem address	(c, s, p)
*		- basic output of decimal numbers 				(d, i, u)
*		- basic output of octal and hex numbers 		(o, x, X)
*		- basic output of floating point numbers		(f)
*		- basic output of percentage signs				(%)
*		- handling flags
*		- handling length
*		- precision and width handling
*/

int	main(void)
{
	// printf("this is a width test%10i!\n", 123);
	// printf("this is a precision & width test %10.5d\n", 123);
	// printf("\n3 + 4 + 5 + 6 = %d\n", add_numbers(4, 3, 4, 5, 6));
	// unsigned int i = 5;
	// unsigned int *ptr = &i;

	// printf("%10% hello%-10dhello\n", 69);
	// printf("%10% hello%10dhello\n", 69);
	// printf("%d this is a test %c\n", 5, 'a');
	// printf("print address of pointer with p: %p\n", ptr);
	// printf("print address of pointer with x: %#lx\n", (long int)&i);
	// printf("print a string with s: %s\n", "hello world");
	// printf("print a string with s + precision: %.8s\n", "hello world");
	// printf("print a character with c: %c\n", 65);
	// printf("% d\n", 25);
	// printf("% d\n", -25);
	// printf("note with width set to '5', the sign is included\n");
	// printf("%+05d\n", 25);
	// printf("%+05d\n", -25);
	// printf("%10.5+d\n", 25);
	// printf("%10+.5-d\n", 25);

	//ft_printf("%hhLd\n", 5);

	int x = 57584;
	ft_printf("\n\nft_printf testing begins!!\n\n");
	ft_printf("hello %d world\n", x);
	ft_printf("hello %d world\n", -205657584);
	ft_printf("hello %%d world %d%%\n", 3, 2);
	//printf("hello %%d world %d\n", 3, 2);
	ft_printf("hello %hld world\n", 5);
	ft_printf("hello %hli world %i\n", 3, 2);
	ft_printf("\noctal conversions:\n\n");
	ft_printf("ft_printf octal: %o\n", 5);
	printf("printf octal: %o\n", 5);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 512);
	printf("printf octal: %o\n", 512);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 7000003);
	printf("printf octal: %o\n", 7000003);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 916);
	printf("printf octal: %o\n", 916);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 24);
	printf("printf octal: %o\n", 24);
	
	ft_printf("\nhexadecimal conversions:\n\n");
	ft_printf("ft_printf hexadecimal: %x\n", 5);
	printf("printf hexadecimal: %x\n", 5);
	ft_printf("\n---------\n");
	ft_printf("ft_printf hexadecimal: %x\n", 512);
	printf("printf hexadecimal: %x\n", 512);
	ft_printf("\n---------\n");
	ft_printf("ft_printf hexadecimal: %x\n", 7000003);
	printf("printf hexadecimal: %x\n", 7000003);
	ft_printf("\n---------\n");
	ft_printf("ft_printf uppercase hexadecimal: %X\n", 1916);
	printf("printf uppercase hexadecimal: %X\n", 1916);
	ft_printf("\n---------\n");
	ft_printf("ft_printf uppercase hexadecimal: %X\n", 10527024);
	printf("printf uppercase hexadecimal: %X\n", 10527024);

	char *str = "...and this is a string in a variable";
	char a = 'a';
	ft_printf("\nstring/char conversions:\n\n");
	ft_printf("\nft_printf string: %s || %s\n", "hello world", str);
	printf("printf string: %s || %s\n", "hello world", str);
	ft_printf("\n---------\n");
	ft_printf("\nft_printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	printf("printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	ft_printf("\n---------\n");
	ft_printf("\nft_printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	printf("printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	return (0);
}
