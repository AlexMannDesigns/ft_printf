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
	//unsigned int i = 5;
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
	ft_printf("\n\n***** memory address testing *****\n\n");
	int i = 5;
	char *ptr2 = "hello world";
	int k = 5;
	int *ptr = &i;
	int *ptr3 = &k;
	printf("printf address test   : *%p*\n", (void *)ptr);
	ft_printf("ft_printf address test: *%p*\n\n", ptr);

	printf("printf    address test, width 3: *%3p*\n", (void *)ptr2);
	ft_printf("ft_printf address test, width 3: *%3p*\n\n", ptr2);

	printf("printf    address test, width 20: *%20p*\n", (void *)ptr3);
	ft_printf("ft_printf address test, width 20: *%20p*\n\n", ptr3);

	printf("printf    address test, width 20, left aligned: *%-20p*\n", (void *)ptr);
	ft_printf("ft_printf address test, width 20, left aligned: *%-20p*\n\n", ptr);

	ft_printf("\n\n***** BIG number testing *****\n\n");
	long long int super_big = 2345678923456781234; //19 digit number is about the limit
	long long int not_so_super_big = 234;
	long long int neg_super_big = -2345678923456781234;
	long long int neg_not_so_super_big = -234;
	int nb = 125;
	int neg_nb = -125567;
	printf("printf    long long test: %lld\n", super_big);
	ft_printf("ft_printf long long test: %lld\n\n", super_big);

	printf("printf    long long hex test: %llx\n", super_big);
	ft_printf("ft_printf long long hex test: %llx\n\n", super_big);

	printf("printf    long long oct test: %llo\n", super_big);
	ft_printf("ft_printf long long oct test: %llo\n\n", super_big);

	printf("printf    long long test: %lld\n", not_so_super_big);
	ft_printf("ft_printf long long test: %lld\n\n", not_so_super_big);

	printf("printf    normal int test: %d\n", nb);
	ft_printf("ft_printf normal int test: %d\n\n", nb);

	printf("printf    normal neg int test: %d\n", neg_nb);
	ft_printf("ft_printf normal neg int test: %d\n\n", neg_nb);

	printf("printf    long long test: %lld\n", neg_super_big);
	ft_printf("ft_printf long long test: %lld\n\n", neg_super_big);

	printf("printf    long long test: %lld\n", neg_not_so_super_big);
	ft_printf("ft_printf long long test: %lld\n\n", neg_not_so_super_big);

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

	printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%d%-10%*\n", 123);
	ft_printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%d%-10%*\n", 123);
	
	printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%-10d%%*\n", 123);
	ft_printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%-10d%%*\n", 123);

	ft_printf("\n\n***** space (' ') flag testing *****\n\n");
	printf("printf space test   : *% d*\n", 25);
	ft_printf("ft_printf space test: *% d*\n\n", 25);

	printf("printf space test, neg int   : *% d*\n", -25);
	ft_printf("ft_printf space test, neg int: *% d*\n\n", -25);

	printf("printf space test, width 2   : *% 2d*\n", 25);
	ft_printf("ft_printf space test, width 2: *% 2d*\n\n", 25);

	printf("printf space test (width 10, precision 6)   : *% 10.6d*\n", 257);
	ft_printf("ft_printf space test (width 10, precision 6): *% 10.6d*\n\n", 257);

	printf("printf space test (width 6, precision 6)   : *% 6.6d*\n", 1234);
	ft_printf("ft_printf space test (width 6, precision 6): *% 6.6d*\n\n", 1234);

	printf("printf space test (width 5, precision 6)   : *% 5.6d*\n", 4321);
	ft_printf("ft_printf space test (width 5, precision 6): *% 5.6d*\n\n", 4321);

	printf("printf space and 0 test (width 10)   : *% 010d*\n", 2727);
	ft_printf("ft_printf space and 0 test (width 10): *% 010d*\n\n", 2727);
	
	ft_printf("\n\n***** plus (+) flag testing *****\n\n");
	printf("printf plus test   : *%+d*\n", 25);
	ft_printf("ft_printf plus test: *%+d*\n\n", 25);

	printf("printf plus test, neg int   : *%+d*\n", -25);
	ft_printf("ft_printf plus test, neg int: *%+d*\n\n", -25);

	printf("printf plus test, width 2   : *%+2d*\n", 27);
	ft_printf("ft_printf plus test, width 2: *%+2d*\n\n", 27);

	printf("printf plus test (width 10, precision 6)   : *%+10.6d*\n", 2734);
	ft_printf("ft_printf plus test (width 10, precision 6): *%+10.6d*\n\n", 2734);

	printf("printf plus test (width 6, precision 6)   : *%+6.6d*\n", 123);
	ft_printf("ft_printf plus test (width 6, precision 6): *%+6.6d*\n\n", 123);

	printf("printf plus test (width 5, precision 6)   : *%+5.6d*\n", 432);
	ft_printf("ft_printf plus test (width 5, precision 6): *%+5.6d*\n\n", 432);

	printf("printf plus and 0 test (width 10)   : *%+010d*\n", 789);
	ft_printf("ft_printf plus and 0 test (width 10): *%+010d*\n", 789);
	
	char *format_bypass = "0 flag with decimal (width 10), left aligned: *%-010d*\n";
	ft_printf("\n\n***** zero (0) flag testing *****\n\n");
	printf("printf 0 flag with decimal (no width):    *%0d*\n", 123);
	ft_printf("ft_printf 0 flag with decimal (no width): *%0d*\n\n", 123);
	printf("printf 0 flag with decimal (width 10):    *%010d*\n", 123);
	ft_printf("ft_printf 0 flag with decimal (width 10): *%010d*\n\n", 123);
	printf("printf    ");
	printf(format_bypass, 123);
	ft_printf("ft_printf ");
	ft_printf(format_bypass, 123);
	ft_printf("\n");
	printf("printf 0 flag with octal (width 10):    *%010o*\n", 123);
	ft_printf("ft_printf 0 flag with octal (width 10): *%010o*\n\n", 123);
	printf("printf 0 flag with octal (width 3):    *%03o*\n", 123);
	ft_printf("ft_printf 0 flag with octal (width 3): *%03o*\n\n", 123);
	printf("printf 0 flag with hexadecimal (width 10):    *%010x*\n", 123);
	ft_printf("ft_printf 0 flag with hexadecimal (width 10): *%010x*\n\n", 123);
	printf("printf 0 flag with hexadecimal and hash (width 10):    *%0#10x*\n", 123);
	ft_printf("ft_printf 0 flag with hexadecimal and hash (width 10): *%0#10x*\n\n", 123);
	printf("printf 0 flag with upper hexadecimal and hash (width 10):    *%0#10X*\n", 123123);
	ft_printf("ft_printf 0 flag with upper hexadecimal and hash (width 10): *%0#10X*\n\n", 123123);

	ft_printf("\n\n***** hash flag testing *****\n\n");
	printf("printf hash flag with octal   : *%#o*\n", 7981);
	ft_printf("ft_printf hash flag with octal: *%#o*\n", 7981);
	printf("printf hash flag with hex   : *%#x*\n", 432);
	ft_printf("ft_printf hash flag with hex: *%#x*\n", 432);
	printf("printf hash flag with upper hex   : *%#X*\n", 123123);
	ft_printf("ft_printf hash flag with upper hex: *%#X*\n", 123123);
	printf("printf hash flag with octal and with 10   : *%#10o*\n", 980);
	ft_printf("ft_printf hash flag with octal and with 10: *%#10o*\n", 980);
	printf("printf hash flag with hex and with 10   : *%#10x*\n", 789123);
	ft_printf("ft_printf hash flag with hex and with 10: *%#10x*\n", 789123);
	printf("printf hash flag with upper hex and with 10   : *%#10X*\n", 234);
	ft_printf("ft_printf hash flag with upper hex and with 10: *%#10X*\n", 234);
	printf("printf hash flag with upper hex and with 10 and precision 6   : *%#10.6X*\n", 234);
	ft_printf("ft_printf hash flag with upper hex and with 10 and precision 6: *%#10.6X*\n", 234);
	printf("printf with upper hex and with 10 and precision 6   : *%10.6X*\n", 789);
	ft_printf("ft_printf with upper hex and with 10 and precision 6: *%10.6X*\n", 789);
	printf("printf hash flag with octal and with 10 and precision 6   : *%#10.6o*\n", 543);
	ft_printf("ft_printf hash flag with octal and with 10 and precision 6: *%#10.6o*\n", 543);
	// //undefined behaviour printf("printf hash flag with decimal and with 10 and precision 6   : *%#10.6d*\n", 234);
	// //undefined behaviour ft_printf("ft_printf hash flag with decimal and with 10 and precision 6: *%#10.6d*\n", 234);

	ft_printf("\n\n***** precision and width testing *****\n\n");

	printf("printf prec 3, neg   : *%.3d*\n", -25);
	ft_printf("ft_printf prec 3, neg: *%.3d*\n\n", -25);

	printf("printf width 1   : *%1d*\n", 25);
	ft_printf("ft_printf width 1: *%1d*\n\n", 25);

	printf("printf width 10   : *%10d*\n", 12345);
	ft_printf("ft_printf width 10: *%10d*\n\n", 12345);

	printf("printf width 20   : *%20d*\n", 78912340);
	ft_printf("ft_printf width 20: *%20d*\n\n", 78912340);

	printf("printf preci 8   : *%.8d*\n", 27);
	ft_printf("ft_printf preci 8: *%.8d*\n\n", 27);

	printf("printf width 4 preci 8   : *%4.8d*\n", 312);
	ft_printf("ft_printf width 4 preci 8: *%4.8d*\n\n", 312);

	printf("printf width 10 precision 4   : *%10.4d*\n", 15);
	ft_printf("ft_printf width 10 precision 4: *%10.4d*\n\n", 15);

	printf("printf width 20 precision 6   : *%20.6d*\n", 234);
	ft_printf("ft_printf width 20 precision 6: *%20.6d*\n\n", 234);

	printf("printf neg width 1   : *%1d*\n", -27);
	ft_printf("ft_printf neg width 1: *%1d*\n\n", -27);

	printf("printf neg width 10   : *%10d*\n", -2785);
	ft_printf("ft_printf neg width 10: *%10d*\n\n", -2785);

	printf("printf neg width 20   : *%20d*\n", -2905654);
	ft_printf("ft_printf neg width 20: *%20d*\n\n", -2905654);

	printf("printf neg preci 8   : *%.8d*\n", -3476);
	ft_printf("ft_printf neg preci 8: *%.8d*\n\n", -3476);

	printf("printf neg width 4 preci 8   : *%4.8d*\n", -271);
	ft_printf("ft_printf neg width 4 preci 8: *%4.8d*\n\n", -271);

	printf("printf neg width 10 precision 4   : *%10.4d*\n", -3);
	ft_printf("ft_printf neg width 10 precision 4: *%10.4d*\n\n", -3);

	printf("printf neg width 20 precision 6   : *%20.6d*\n", -34);
	ft_printf("ft_printf neg width 20 precision 6: *%20.6d*\n\n", -34);

	printf("printf precision 6, left aligned   : *%-.6d*\n", 212);
	ft_printf("ft_printf precision 6, left aligned: *%-.6d*\n\n", 212);
	printf("printf precision 6, width 6   : *%6.6d*\n", 765);
	ft_printf("ft_printf precision 6, width 6: *%6.6d*\n\n", 765);
	printf("printf precision 6, width 7 left aligned   : *%-7.6d*\n", 341);
	ft_printf("ft_printf precision 6, width 7 left aligned: *%-7.6d*\n\n", 341);
	printf("printf width 20 precision 6, left aligned   : *%-20.6d*\n", 129856);
	ft_printf("ft_printf width 20 precision 6, left aligned: *%-20.6d*\n\n", 129856);

	printf("printf neg precision 6, left aligned   : *%-.6d*\n", -212);
	ft_printf("ft_printf neg precision 6, left aligned: *%-.6d*\n\n", -212);
	printf("printf neg precision 6, width 6   : *%6.6d*\n", -765);
	ft_printf("ft_printf neg precision 6, width 6: *%6.6d*\n\n", -765);
	printf("printf neg precision 6, width 7 left aligned   : *%-7.6d*\n", -341);
	ft_printf("ft_printf neg precision 6, width 7 left aligned: *%-7.6d*\n\n", -341);
	printf("printf neg width 20 precision 6, left aligned   : *%-20.6d*\n", -129856);
	ft_printf("ft_printf neg width 20 precision 6, left aligned: *%-20.6d*\n\n", -129856);

	printf("printf string test width 20   : *%20s*\n", "hello world");
	ft_printf("ft_printf string test width 20: *%20s*\n\n", "hello world");
	printf("printf string test width 20, left aligned   : *%-20s*\n", "hello world");
	ft_printf("ft_printf string test width 20, left aligned: *%-20s*\n\n", "hello world");
	printf("printf string test width 20 precision 20   : *%20.20s*\n", "hello world");
	ft_printf("ft_printf string test width 20 precision 20: *%20.20s*\n\n", "hello world");
	printf("printf string test precision 20   : *%.20s*\n", "hello world");
	ft_printf("ft_printf string test precision 20: *%.20s*\n\n", "hello world");
	// //undefined behaviour printf("printf char test precision 20   : *%.20c*\n", 'c');
	// //undefined behaviour ft_printf("ft_printf char test precision 20: *%.20c*\n\n", 'c');
	printf("printf hex test width 20 precision 20   : *%20.20x*\n", 1234);
	ft_printf("ft_printf hex test width 20 precision 20: *%20.20x*\n\n", 1234);
	printf("printf oct test width 20 precision 20   : *%20.20o*\n", 1234);
	ft_printf("ft_printf oct test width 20 precision 20: *%20.20o*\n\n", 1234);


	// ft_printf("\n\ntesting return values:\nprintf = %d  ft_printf = %d\n", printf("hello %5d world", 123), ft_printf("hello %5d world", 123));
	// ft_printf("%hhLd\n", 5);


	ft_printf("\noctal conversions:\n\n");
	ft_printf("ft_printf octal: %o\n", 5);
	printf("printf octal   : %o\n", 5);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 512);
	printf("printf octal   : %o\n", 512);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 7000003);
	printf("printf octal   : %o\n", 7000003);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 916);
	printf("printf octal   : %o\n", 916);
	ft_printf("\n---------\n");
	ft_printf("ft_printf octal: %o\n", 24);
	printf("printf octal   : %o\n", 24);
	
	ft_printf("\nhexadecimal conversions:\n\n");
	ft_printf("ft_printf hexadecimal: %x\n", 5);
	printf("printf hexadecimal   : %x\n", 5);
	ft_printf("\n---------\n");
	ft_printf("ft_printf hexadecimal: %x\n", 512);
	printf("printf hexadecimal   : %x\n", 512);
	ft_printf("\n---------\n");
	ft_printf("ft_printf hexadecimal: %x\n", 7000003);
	printf("printf hexadecimal   : %x\n", 7000003);
	ft_printf("\n---------\n");
	ft_printf("ft_printf uppercase hexadecimal: %X\n", 1916);
	printf("printf uppercase hexadecimal   : %X\n", 1916);
	ft_printf("\n---------\n");
	ft_printf("ft_printf uppercase hexadecimal: %X\n", 10527024);
	printf("printf uppercase hexadecimal   : %X\n", 10527024);

	char *str = "...and this is a string in a variable";
	char a = 'a';
	ft_printf("\nstring/char conversions:\n\n");
	ft_printf("\nft_printf string: %s || %s\n", "hello world", str);
	printf("printf string   : %s || %s\n", "hello world", str);
	ft_printf("\n---------\n");
	ft_printf("\nft_printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	printf("printf string   : %s || %s || check digits still work: %d\n", "hello world", str, 123);
	ft_printf("\n---------\n");
	ft_printf("\nft_printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	printf("printf char   : %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	ft_printf("\n---------\n");
	printf("\nprintf    char test with number outside of ASCII range: %c\n", 312);
	ft_printf("ft_printf char test with number outside of ASCII range: %c\n", 312);
	return (0);
}
