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
	unsigned int i = 5;
	//unsigned int *ptr = &i;

	// printf("%10% hello%-10dhello\n", 69);
	// printf("%10% hello%10dhello\n", 69);
	// printf("%d this is a test %c\n", 5, 'a');
	// printf("print address of pointer with p: %p\n", &i);
	// printf("print address of pointer with x: %#lx\n", (long int)&i);
	// ft_printf("ft_printf address of pointer with p: %p\n", &i);
	// printf("print a string with s: %s\n", "hello world");
	// printf("print a string with s + precision: %.8s\n", "hello world");
	// printf("print a character with c: %c\n", 65);
	// printf("% d\n", 25);
	// printf("% d\n", -25);
	// printf("note with width set to '5', the sign is included\n");

	ft_printf("\n\n***** percent sign (%%) testing *****\n\n");

	printf("this is what a percent sign should look like: *%%*\n");
	ft_printf("this is what a percent sign should look like: *%%*\n");

	printf("this is what a percent sign should look like, width 5: *%5%*\n");
	ft_printf("this is what a percent sign should look like, width 5: *%5%*\n");

	printf("this is what a percent sign should look like, precision 5: *%.5%*\n");
	ft_printf("this is what a percent sign should look like, precision 5: *%.5%*\n");

	printf("this is what a percent sign should look like, space flag: *% %*\n");
	ft_printf("this is what a percent sign should look like, space flag: *% %*\n");
	
	printf("this is what a percent sign should look like, plus flag: *%+%*\n");
	ft_printf("this is what a percent sign should look like, plus flag: *%+%*\n");

	printf("this is what a percent sign should look like, minus (left align) flag, width 10: *%-10%*\n");
	ft_printf("this is what a percent sign should look like, minus (left align) flag, width 10: *%-10%*\n");

	// ft_printf("\n\n***** space (' ') flag testing *****\n\n");
	// printf("printf space test   : *% d*\n", 25);
	// ft_printf("ft_printf space test: *% d*\n", 25);
	// printf("printf space test, neg int   : *% d*\n", -25);
	// ft_printf("ft_printf space test, neg int: *% d*\n", -25);
	// printf("printf space test (width 10, precision 6)   : *% 10.6d*\n", 257);
	// ft_printf("ft_printf space test (width 10, precision 6): *% 10.6d*\n", 257);
	// printf("printf space test (width 6, precision 6)   : *% 6.6d*\n", 257);
	// ft_printf("ft_printf space test (width 6, precision 6): *% 6.6d*\n", 257);
	// printf("printf space test (width 5, precision 6)   : *% 5.6d*\n", 257);
	// ft_printf("ft_printf space test (width 5, precision 6): *% 5.6d*\n", 257);
	// printf("printf space and 0 test (width 10)   : *% 010d*\n", 257);
	// ft_printf("ft_printf space and 0 test (width 10): *% 010d*\n", 257);
	
	// ft_printf("\n\n***** plus (+) flag testing *****\n\n");
	// printf("printf plus test   : *%+d*\n", 25);
	// ft_printf("ft_printf plus test: *%+d*\n", 25);
	// printf("printf plus test, neg int   : *%+d*\n", -25);
	// ft_printf("ft_printf plus test, neg int: *%+d*\n", -25);
	// printf("printf plus test (width 10, precision 6)   : *%+10.6d*\n", 257);
	// ft_printf("ft_printf plus test (width 10, precision 6): *%+10.6d*\n", 257);
	// printf("printf plus test (width 6, precision 6)   : *%+6.6d*\n", 257);
	// ft_printf("ft_printf plus test (width 6, precision 6): *%+6.6d*\n", 257);
	// printf("printf plus test (width 5, precision 6)   : *%+5.6d*\n", 257);
	// ft_printf("ft_printf plus test (width 5, precision 6): *%+5.6d*\n", 257);
	// printf("printf plus and 0 test (width 10)   : *%+010d*\n", 257);
	// ft_printf("ft_printf plus and 0 test (width 10): *%+010d*\n", 257);
	
	// ft_printf("\n\n***** zero (0) flag testing *****\n\n");
	// printf("printf 0 flag with decimal (no width):    *%0d*\n", 123);
	// ft_printf("ft_printf 0 flag with decimal (no width): *%0d*\n", 123);
	// printf("printf 0 flag with decimal (width 10):    *%010d*\n", 123);
	// ft_printf("ft_printf 0 flag with decimal (width 10): *%010d*\n", 123);
	// printf("printf 0 flag with octal (width 10):    *%010o*\n", 123);
	// ft_printf("ft_printf 0 flag with octal (width 10): *%010o*\n", 123);
	// printf("printf 0 flag with octal (width 3):    *%03o*\n", 123);
	// ft_printf("ft_printf 0 flag with octal (width 3): *%03o*\n", 123);
	// printf("printf 0 flag with hexadecimal (width 10):    *%010x*\n", 123);
	// ft_printf("ft_printf 0 flag with hexadecimal (width 10): *%010x*\n", 123);
	// printf("printf 0 flag with hexadecimal and hash (width 10):    *%0#10x*\n", 123);
	// ft_printf("ft_printf 0 flag with hexadecimal and hash (width 10): *%0#10x*\n", 123);
	// printf("printf 0 flag with upper hexadecimal and hash (width 10):    *%0#10X*\n", 123123);
	// ft_printf("ft_printf 0 flag with upper hexadecimal and hash (width 10): *%0#10X*\n", 123123);

	// ft_printf("\n\n***** hash flag testing *****\n\n");
	// printf("printf hash flag with octal   : *%#o*\n", 234);
	// ft_printf("ft_printf hash flag with octal: *%#o*\n", 234);
	// printf("printf hash flag with hex   : *%#x*\n", 234);
	// ft_printf("ft_printf hash flag with hex: *%#x*\n", 234);
	// printf("printf hash flag with upper hex   : *%#X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex: *%#X*\n", 234);
	// printf("printf hash flag with octal and with 10   : *%#10o*\n", 234);
	// ft_printf("ft_printf hash flag with octal and with 10: *%#10o*\n", 234);
	// printf("printf hash flag with hex and with 10   : *%#10x*\n", 234);
	// ft_printf("ft_printf hash flag with hex and with 10: *%#10x*\n", 234);
	// printf("printf hash flag with upper hex and with 10   : *%#10X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex and with 10: *%#10X*\n", 234);
	// printf("printf hash flag with upper hex and with 10 and precision 6   : *%#10.6X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex and with 10 and precision 6: *%#10.6X*\n", 234);
	// printf("printf with upper hex and with 10 and precision 6   : *%10.6X*\n", 234);
	// ft_printf("ft_printf with upper hex and with 10 and precision 6: *%10.6X*\n", 234);
	// printf("printf hash flag with octal and with 10 and precision 6   : *%#10.6o*\n", 234);
	// ft_printf("ft_printf hash flag with octal and with 10 and precision 6: *%#10.6o*\n", 234);
	// printf("printf hash flag with decimal and with 10 and precision 6   : *%#10.6d*\n", 234);
	// ft_printf("ft_printf hash flag with decimal and with 10 and precision 6: *%#10.6d*\n", 234);

	// ft_printf("\n\n***** precision and width testing *****\n\n");
	// printf("printf width 1   : *%1d*\n", 25);
	// ft_printf("ft_printf width 1: *%1d*\n\n", 25);
	// printf("printf width 10   : *%10d*\n", 25);
	// ft_printf("ft_printf width 10: *%10d*\n\n", 25);
	// printf("printf width 20   : *%20d*\n", 25);
	// ft_printf("ft_printf width 20: *%20d*\n\n", 25);
	// printf("printf preci 8   : *%.8d*\n", 25);
	// ft_printf("ft_printf preci 8: *%.8d*\n\n", 25);
	// printf("printf width 4 preci 8   : *%4.8d*\n", 25);
	// ft_printf("ft_printf width 4 preci 8: *%4.8d*\n\n", 25);
	// printf("printf width 10 precision 4   : *%10.4d*\n", 25);
	// ft_printf("ft_printf width 10 precision 4: *%10.4d*\n\n", 25);
	// printf("printf width 20 precision 6   : *%20.6d*\n", 25);
	// ft_printf("ft_printf width 20 precision 6: *%20.6d*\n\n", 25);
	// printf("printf string test width 20   : *%20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20: *%20s*\n\n", "hello world");
	// printf("printf string test width 20, left aligned   : *%-20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20, left aligned: *%-20s*\n\n", "hello world");
	// printf("printf precision 6, left aligned   : *%-.6d*\n", 25);
	// ft_printf("ft_printf precision 6, left aligned: *%-.6d*\n\n", 25);
	// printf("printf precision 6, width 6   : *%6.6d*\n", 25);
	// ft_printf("ft_printf precision 6, width 6: *%6.6d*\n\n", 25);
	// printf("printf precision 6, width 7 left aligned   : *%-7.6d*\n", 25);
	// ft_printf("ft_printf precision 6, width 7 left aligned: *%-7.6d*\n\n", 25);
	// printf("printf width 20 precision 6, left aligned   : *%-20.6d*\n", 25);
	// ft_printf("ft_printf width 20 precision 6, left aligned: *%-20.6d*\n\n", 25);
	// printf("printf string test width 20 precision 20   : *%20.20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20 precision 20: *%20.20s*\n\n", "hello world");
	// printf("printf string test precision 20   : *%.20s*\n", "hello world");
	// ft_printf("ft_printf string test precision 20: *%.20s*\n\n", "hello world");
	// printf("printf char test precision 20   : *%.20c*\n", 'c');
	// ft_printf("ft_printf char test precision 20: *%.20c*\n\n", 'c');
	// printf("printf address test precision 20   : *%.20p*\n", &i);
	// ft_printf("ft_printf address test precision 20: *%.20p*\n\n", &i);
	// printf("printf hex test width 20 precision 20   : *%20.20x*\n", 1234);
	// ft_printf("ft_printf hex test width 20 precision 20: *%20.20x*\n\n", 1234);
	// printf("printf oct test width 20 precision 20   : *%20.20o*\n", 1234);
	// ft_printf("ft_printf oct test width 20 precision 20: *%20.20o*\n\n", 1234);


	// // ft_printf("\n\ntesting return values:\nprintf = %d  ft_printf = %d\n", printf("hello %5d world", 123), ft_printf("hello %5d world", 123));
	// // ft_printf("%hhLd\n", 5);

	// int x = 57584;
	// ft_printf("\n\nft_printf testing begins!!\n\n");
	// ft_printf("hello %d world\n", x);
	// ft_printf("hello %d world\n", -205657584);
	// //ft_printf("hello %%d world %d%%\n", 3, 2);
	// //printf("hello %%d world %d\n", 3, 2);
	// ft_printf("hello %hld world\n", 5);
	// ft_printf("hello %hli world %i\n", 3, 2);
	// ft_printf("\noctal conversions:\n\n");
	// ft_printf("ft_printf octal: %o\n", 5);
	// printf("printf octal: %o\n", 5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 512);
	// printf("printf octal: %o\n", 512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 7000003);
	// printf("printf octal: %o\n", 7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 916);
	// printf("printf octal: %o\n", 916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 24);
	// printf("printf octal: %o\n", 24);
	
	// ft_printf("\nhexadecimal conversions:\n\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 5);
	// printf("printf hexadecimal: %x\n", 5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 512);
	// printf("printf hexadecimal: %x\n", 512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 7000003);
	// printf("printf hexadecimal: %x\n", 7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf uppercase hexadecimal: %X\n", 1916);
	// printf("printf uppercase hexadecimal: %X\n", 1916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf uppercase hexadecimal: %X\n", 10527024);
	// printf("printf uppercase hexadecimal: %X\n", 10527024);

	// char *str = "...and this is a string in a variable";
	// char a = 'a';
	// ft_printf("\nstring/char conversions:\n\n");
	// ft_printf("\nft_printf string: %s || %s\n", "hello world", str);
	// printf("printf string: %s || %s\n", "hello world", str);
	// ft_printf("\n---------\n");
	// ft_printf("\nft_printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	// printf("printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	// ft_printf("\n---------\n");
	// ft_printf("\nft_printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	// printf("printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	return (0);
}
