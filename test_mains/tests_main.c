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
#include <stdio.h>

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
	
	
	// system("ft_printf leaks");

	/* GENERAL LEAK TEST */
	// int i = 0;
	// while (i < 10000000)
	// {
	// 	ft_printf("%s", "");
	// 	i++;
	// }
   
//    char	*compiler_tricker = "printf   : *%-0+5d*\n";
	// printf(compiler_tricker, 42);
	// ft_printf("ft_printf: *%-0+5d*\n\n", 42);
	// ft_printf("ft_printf: *%-+5d*\n\n", 42);
	// compiler_tricker = "printf   : %####0000 33..1..#00d\\n";
	// printf(compiler_tricker, 256);
	// ft_printf("\nft_printf: %####0000 33..1..#00d\\n", 256);
	// ft_printf("\n");
	// compiler_tricker = "printf   : *%####0000 33..1d*\n";
	// printf(compiler_tricker, 256);
	// ft_printf("ft_printf: *%####0000 33..1d*\n\n", 256);
	// compiler_tricker = "printf   : %###-#0000 33...12..#0+0d\n";
	// printf(compiler_tricker, 256);
	// ft_printf("ft_printf: %###-#0000 33...12..#0+0d\n\n", 256);

	// ft_printf("****** SIZE_T/SSIZE_T TESTING *****\n\n");

	// size_t uzs = 1;
    // ssize_t zs = -1;

	// ft_printf("size of size_t in bytes:	%d\n\n", sizeof(size_t));
	// ft_printf("size of ssize_t in bytes:	%d\n\n", sizeof(ssize_t));

    // printf ("printf size_t zu   : %zu\n", uzs);
	// ft_printf ("ft_printf size_t zu: %zu\n\n", uzs);

    // printf ("printf ssize_t zd   : %zd\n", uzs);
	// ft_printf ("ft_printf ssize_t zd: %zd\n\n", uzs);

    // printf ("printf ssize_t zu   : %zu\n", zs);
	// ft_printf ("ft_printf ssize_t zu: %zu\n\n", zs);
	
    // printf ("printf ssize_t zd   : %zd\n", zs);
	// ft_printf ("ft_printf ssize_t zd: %zd\n\n", zs);

	// ssize_t min = LONG_MIN;
	// printf ("printf LONG_MIN ssize_t zd   : %zd\n", min);
	// ft_printf ("ft_printf LONG_MIN ssize_t zd: %zd\n\n", min);

	// printf ("printf LONG_MIN zu   : %zu\n", LONG_MIN);
	// ft_printf ("ft_printf LONG_MIN zu: %zu\n\n", LONG_MIN);

	// char *s = "printf LONG_MIN zu   : %u\n";
	// printf (s, LONG_MIN);
	// ft_printf ("ft_printf LONG_MIN zu: %u\n\n", LONG_MIN);


	// ft_printf("***** UNDEFINED *****\n\n");
	// printf("printf   : %05.10%%c\n", 'a');
	// ft_printf("ft_printf: %05.10%%c\n\n", 'a');

	// char *compiler_trick = "%06s%c\n";
	// printf("printf   : ");
	// printf(compiler_trick, "yoyo", 'a');
	// ft_printf("ft_printf: ");
	// ft_printf(compiler_trick, "yoyo", 'a');
	// ft_printf("\n");

	// compiler_trick = "%%   %";
	// printf("printf   : *");
	// printf(compiler_trick, "test");
	// printf("*\n");

	// printf("printf    *% -1.0d*\n", 0);
	// ft_printf("ft_printf *% -1.0d*\n\n", 0);
	
	// printf("printf    *% -.0d*\n", 0);
	// ft_printf("ft_printf *% -.0d*\n\n", 0);

	// printf("printf    *% -.0d*\n", 0);
	// ft_printf("ft_printf *% -.0d*\n\n", 0);

	// printf("printf    *% -1d*\n", 0);
	// ft_printf("ft_printf *% -1d*\n\n", 0);

	// printf("printf    *%+1.0d*\n", 0);
	// ft_printf("ft_printf *%+1.0d*\n\n", 0);

	// printf("printf    *%+.0d*\n", 42);
	// ft_printf("ft_printf *%+.0d*\n\n", 42);

	// printf("printf    *% 1.0d*\n", 0);
	// ft_printf("ft_printf *% 1.0d*\n\n", 0);

	// printf("printf    *%1.0d*\n", 0);
	// ft_printf("ft_printf *%1.0d*\n\n", 0);
	// printf("printf    *% -1.0d*\n", 42);
	// ft_printf("ft_printf *% -1.0d*\n\n", 42);

	// short fortytwo = 42;
	// printf("printf    *%05.0hd*\n", fortytwo);
	// ft_printf("ft_printf *%05.0hd*\n\n", fortytwo);
	// printf("printf    *%05.0ld*\n", 42L);
	// ft_printf("ft_printf *%05.0ld*\n\n", 42L);
	// printf("printf    *%05.0d*\n", 42);
	// ft_printf("ft_printf *%05.0d*\n\n", 42);

	// printf("printf    *%05.0hu*\n", fortytwo);
	// ft_printf("ft_printf *%05.0hu*\n\n", fortytwo);
	// printf("printf    *%05.0lu*\n", 42L);
	// ft_printf("ft_printf *%05.0lu*\n\n", 42L);


	// ft_printf("\n\n***** colour testing *****\n\n");

	
	// int p_ret = printf("printf:    Le fichier \033[0;31m%s\033[0m contient : \033[0;31m%s\033[0m\n\n", "hello", "world");

	// int fp_ret = ft_printf("ft_printf: Le fichier {red}%s{reset} contient {basil}: {blue}%s{reset}\n\n", "hello", "world");

	// ft_printf("%d\n", p_ret);
	// ft_printf("%d\n", fp_ret);
	// fp_ret = ft_printf("ft_printf: Le fichier %s contient {basil}: %s\n\n", "hello", "world");
	// ft_printf("%d\n", fp_ret);

	// ft_printf("ft_printf: {red}Le {blue}fichier %s {green}{bleu}contient{rouge} {purple}{sininen} {red red {re,d}blue}abc{reset}: %s {black\n\n", "hello", "world");

	// ft_putendl("\ntesting all colours with the following string:");
	// ft_putendl("{red}LOOK {cyan}AT {purple}ALL {green}THE {yellow}PRETTY {blue}COLOURS! {green}ISN'T {white}THIS {red}AMAZING{green}!{black}!{red}!{blue}!{white}!{purple}!{reset}\n");
	// ft_printf("{red}LOOK {cyan}AT {purple}ALL {green}THE {yellow}PRETTY {blue}COLOURS! {green}ISN'T {white}THIS {red}AMAZING{green}!{black}!{red}!{blue}!{white}!{purple}!{reset}\n\n");
	// ft_printf("{red}HELLO %d {blue}WORLD {reset}*%-#20.9x{green}*\n", 512, 1234567);
	// ft_printf("HELLO {reset} WORLD\n\n", 512, 1234567);
	// ft_printf("HELLO {reset} WORLD{purple}");
	// ft_printf("\nHELLO {reset} WORLD\n");
	// ft_printf("{");
	// ft_printf("\n");
	// ft_printf("{   }");
	// ft_printf("\n");
	// ft_printf("{}");
	// ft_printf("\n");
	// ft_printf("{BLACK}");
	// ft_printf("\n");

	// ft_printf("hello {} {} {} hello");
	// ft_printf("\n");
	// ft_printf("{reset}");
	// ft_printf("\n");
	// ft_printf("hello {} world\n");


	// ft_printf("\n\n***** n flag testing *****\n\n");
	// int n_flag = 0;
	// long n_flag_long = 0;
	// long long n_flag_llong = 0;
	// char n_flag_char = 0;
	// short n_flag_short = 0;
	// printf("printf...\n\n");
	// printf("this is%n a test\n", &n_flag);
	// printf("n_flag = %d\n", n_flag);
	// printf("this is another%n test\n", &n_flag);
	// printf("n_flag = %d\n", n_flag);
	// printf("%nthis is yet another test\n", &n_flag);
	// printf("n_flag = %d\n", n_flag);
	// printf("th%nis is yet another test\n", &n_flag);
	// printf("n_flag = %d\n", n_flag);
	// printf("this%ln is yet another test, this time with l mod\n", &n_flag_long);
	// printf("n_flag_long = %ld\n", n_flag_long);
	// printf("this%lln is yet another test, this time with ll mod\n", &n_flag_llong);
	// printf("n_flag_llong = %lld\n", n_flag_llong);
	// printf("this%hhn is yet another test, this time with char mod\n", &n_flag_char);
	// printf("n_flag_char = %hhd\n", n_flag_char);
	// printf("this%hn is yet another test, this time with short mod\n", &n_flag_short);
	// printf("n_flag_char = %hd\n\n", n_flag_short);


	// ft_printf("ft_printf...\n\n");
	// ft_printf("this is%n a test\n", &n_flag);
	// ft_printf("n_flag = %d\n", n_flag);
	// ft_printf("this is another%n test\n", &n_flag);
	// ft_printf("n_flag = %d\n", n_flag);
	// ft_printf("%nthis is yet another test\n", &n_flag);
	// ft_printf("n_flag = %d\n", n_flag);
	// ft_printf("th%nis is yet another test\n", &n_flag);
	// ft_printf("n_flag = %d\n", n_flag);
	// ft_printf("this%ln is yet another test, this time with l mod\n", &n_flag_long);
	// ft_printf("n_flag_long = %ld\n", n_flag_long);
	// ft_printf("this%lln is yet another test, this time with ll mod\n", &n_flag_llong);
	// ft_printf("n_flag_llong = %lld\n", n_flag_llong);
	// ft_printf("this%hhn is yet another test, this time with char mod\n", &n_flag_char);
	// ft_printf("n_flag_char = %hhd\n", n_flag_char);
	// ft_printf("this%hn is yet another test, this time with short mod\n", &n_flag_short);
	// ft_printf("n_flag_char = %hd\n\n", n_flag_short);

	// char *comp_trck = "printf    this is%10n a test\n";
	// char *comp_trck2 = "printf    this is%10.10n a test\n";
	// ft_printf("n flag undefined behaviours....\n\n");
	// printf(comp_trck, &n_flag);
	// ft_printf("ft_printf this is%10n a test\n", &n_flag);
	// printf(comp_trck2, &n_flag);
	// ft_printf("ft_printf this is%10.10n a test\n", &n_flag);

	// ft_printf("\n\n***** binary (b) flag testing *****\n\n");
	// ft_printf("binary test (expected output = 1111011): %b\n", 123);
	// ft_printf("binary test (expected output = 11110000001111000): %b\n", 123000);
	// ft_printf("binary test (expected output = 1100010101): %b\n", 789);
	// ft_printf("binary test (expected output = 11111111111111111111111111101100): %b\n", -20);
	// ft_printf("binary test (expected output = 111111111111111111111111111111111111111111111111111111111111111): %llb\n", LLONG_MAX);
	// ft_printf("binary test (expected output = 0):	%b\n", LLONG_MIN);
	// ft_printf("binary test (expected output = 11):	%b\n", 3);
	// ft_printf("binary test (expected output = 0):	%b\n", 0);

	// ft_printf("\n\n***** 42 filechecker testing *****\n\n");
	
	// printf("printf new neg process test   : %ld\n", -123456123456L);
	// ft_printf("ft_printf new neg process test: %ld\n\n", -123456123456L);
	
	// printf("printf new neg process test   : %ld\n", 8234561234567891234);
	// ft_printf("ft_printf new neg process test: %ld\n\n", 8234561234567891234);
	// char *percent = "%";
	// ft_printf("printf    : *");
	// int ret1 = printf(percent, 0);
	// ft_printf("*\n");
	// ft_printf("ft_printf : *");
	// int ret2 = ft_printf(percent, 0);
	// ft_printf("*\n");
	// printf("printf ret    = %d\n", ret1);
	// printf("ft_printf ret = %d\n", ret2);
	// printf("printf CHAR_MIN:   	*%d*\n", CHAR_MIN);
	// ft_printf("ft_printf CHAR_MIN:	*%d*\n\n", CHAR_MIN);

	// printf("printf INT_MIN:   	*%d*\n", INT_MIN);
	// ft_printf("ft_printf INT_MIN:	*%d*\n\n", INT_MIN);

	// printf("printf LONG_MIN:   	*%ld*\n", LONG_MIN);
	// ft_printf("ft_printf LONG_MIN:	*%ld*\n\n", LONG_MIN);

	// printf("printf LLONG_MIN:   	*%lld*\n", LLONG_MIN);
	// ft_printf("ft_printf LLONG_MIN:	*%lld*\n\n", LLONG_MIN);

	// printf("printf INT_MAX:   	*%d*\n", INT_MAX);
	// ft_printf("ft_printf INT_MAX:	*%d*\n\n", INT_MAX);

	// printf("printf LONG_MAX:   	*%ld*\n", LONG_MAX);
	// ft_printf("ft_printf LONG_MAX:	*%ld*\n\n", LONG_MAX);

	// printf("printf LLONG_MAX:   	*%lld*\n", LLONG_MAX);
	// ft_printf("ft_printf LLONG_MAX:	*%lld*\n\n", LLONG_MAX);

	// printf("printf:    *%+03d*\n", 123456);
	// ft_printf("ft_printf: *%+03d*\n\n", 123456);

	// printf("printf,    percent with 0 flag and width 5: *%05%*\n");
	// ft_printf("ft_printf, percent with 0 flag and width 5: *%05%*\n\n");
	
	// printf("printf,    percent with prec 5 and width 5: *%5.5%*\n");
	// ft_printf("ft_printf, percent with prec 5 and width 5: *%5.5%*\n\n");

	// printf("printf,    p flag with NULL: *%p*\n", NULL);
	// ft_printf("ft_printf, p flag with NULL: *%p*\n\n", NULL);

	// printf("printf,    width 5 with NULL: *%5p*\n", NULL);
	// ft_printf("ft_printf, width 5 with NULL: *%5p*\n\n", NULL);

	// printf("printf,    d with 0 flag, width 4, neg val: *%04d*\n", -4825);
	// ft_printf("ft_printf, d with 0 flag, width 4, neg val: *%04d*\n\n", -4825);

	// printf("printf,    i with 0 flag, width 4, neg val: *%04i*\n", -4825);
	// ft_printf("ft_printf, i with 0 flag, width 4, neg val: *%04i*\n\n", -4825);

	// printf("printf,    i, width 4, neg val: *%4i*\n", -4825);
	// ft_printf("ft_printf, i, width 4, neg val: *%4i*\n\n", -4825);

	// int forty_two = -42;
	// unsigned long int neg_42 = (unsigned long int) forty_two;
	// printf("printf negative unsigned long:    *%lu*\n", neg_42);
	// ft_printf("ft_printf negative unsigned long: *%lu*\n\n", neg_42);
 	
	// long long max_ll =  9223372036854775807;
	// long long min_ll =  -9223372036854775807;

	// printf("printf signed long long max   : *%lld*\n", max_ll);
	// ft_printf("ft_printf signed long long max: *%lld*\n\n", max_ll);

	// printf("printf signed long long min   : *%lld*\n", min_ll);
	// ft_printf("ft_printf signed long long min: *%lld*\n\n", min_ll);

	// printf("printf signed long long max, hexadecimal   : *%llx*\n", max_ll);
	// ft_printf("ft_printf signed long long max, hexadecimal: *%llx*\n\n", max_ll);

	// printf("printf signed long long min, hexadecimal   : *%llx*\n", min_ll);
	// ft_printf("ft_printf signed long long min, hexadecimal: *%llx*\n\n", min_ll);

	// printf("printf, long long caps hex:    *%llX*\n", (long long)4294967296);
	// ft_printf("ft_printf, long long caps hex: *%llX*\n\n", (long long)4294967296);

	// printf("printf, hex nil value and hash flag:    *%#x*\n", 0);
 	// ft_printf("ft_printf, hex nil value and hash flag: *%#x*\n\n", 0);

	// printf("printf:   hex nil value, hash flag, zero precision: *%#.x* *%#.0x*\n", 0, 0);
	// ft_printf("ft_printf hex nil value, hash flag, zero precision: *%#.x* *%#.0x*\n\n", 0, 0);

	// printf("printf, hex and hash flag:    *%#x*\n", 7);
 	// ft_printf("ft_printf, hex and hash flag: *%#x*\n\n", 7);

	// printf("printf:   hex, hash flag, zero precision: *%#.x* *%#.0x*\n", 7, 7);
 	// ft_printf("ft_printf hex, hash flag, zero precision: *%#.x* *%#.0x*\n\n", 7, 7);
 	
 	// printf("printf:   hex nil value, zero precision: *%.x* *%.0x*\n", 0, 0);
	// ft_printf("ft_printf hex nil value, zero precision: *%.x* *%.0x*\n\n", 0, 0);
 	
 	// printf("printf:   hex, nil value width 5, precision zero: *%5.x* *%5.0x*\n", 0, 0);
	// ft_printf("ft_printf hex, nil value width 5, precision zero: *%5.x* *%5.0x*\n\n", 0, 0);

	// printf("printf:   hex, zero precision: *%.x* *%.0x*\n", 8, 8);
	// ft_printf("ft_printf hex, zero precision: *%.x* *%.0x*\n\n", 8, 8);
 	
 	// printf("printf:   hex, width 5, precision zero: *%5.x* *%5.0x*\n", 8, 8);
	// ft_printf("ft_printf hex, width 5, precision zero: *%5.x* *%5.0x*\n\n", 8, 8);

	// printf("printf, neg, 0 flag   :		*%05d*\n", -42);
	// ft_printf("ft_printf printf, neg, 0 flag:	*%05d*\n\n", -42);
 	
	// printf("printf, neg, 0 and plus flags   :	*%0+5d*\n", -42);
 	// ft_printf("ft_printf, neg, 0 and plus flags:	*%0+5d*\n\n", -42);

	// printf("printf, NULL char   :	*%c*\n", 0);
 	// ft_printf("ft_printf, NULL char:	*%c*\n\n", 0);

	// printf("printf, NULL char, width 3   :	*%3c*\n", 0);
	// ft_printf("ft_printf, NULL char, width 3:	*%3c*\n\n", 0);

	// printf("printf    decimal, left aligned, width 5, precision 10: *%-5.10d*\n", 2500);
	// ft_printf("ft-printf decimal, left aligned, width 5, precision 10: *%5.10d*\n\n", 2500);

	// printf("printf    hex, left aligned, width 5, precision 10: *%-5.10x*\n", 2500);
	// ft_printf("ft-printf hex, left aligned, width 5, precision 10: *%-5.10x*\n\n", 2500);
	// printf("printf    hex, zero flag, width 5, precision 10: *%05.10x*\n", 2500);
	// ft_printf("ft-printf hex, zero flag, width 5, precision 10: *%05.10x*\n\n", 2500);

	// printf("printf    octal, left aligned, width 5, precision 10: *%-5.10o*\n", 2500);
	// ft_printf("ft-printf octal, left aligned, width 5, precision 10: *%-5.10o*\n\n", 2500);

	// printf("printf    octal, precision 0, hash flag, value 0 : %#.o %#.0o\n", 0, 0);
	// ft_printf("ft_printf octal, precision 0, hash flag, value 0 : %#.o %#.0o\n\n", 0, 0);

	// printf("printf    octal, precision 0, value 0 : %.o %.0o\n", 0, 0);
	// ft_printf("ft_printf octal, precision 0, value 0 : %.o %.0o\n\n", 0, 0);
	// char    *format_trick1 = "	*%x*\n";
	// char    *format_trick2 = "	*%X*\n";
	// char    *format_trick3 = "	*%hx*\n";
	// char    *format_trick4 = "	*%hhX*\n";

	// printf("printf -42: ");
	// printf(format_trick1, -42);
	// ft_printf("ft_printf -42: ");
	// ft_printf(format_trick1, -42);
	// ft_printf("\n");
	
	// ft_printf("printf -42: ");
	// printf(format_trick2, -42);
	// ft_printf("ft_printf -42: ");
	// ft_printf(format_trick2, -42);
	// ft_printf("\n");

	// ft_printf("printf 42: ");
	// printf(format_trick1, 42);
	// ft_printf("ft_printf 42: ");
	// ft_printf(format_trick1, 42);
	// ft_printf("\n");

	// ft_printf("printf 4294967296: ");
	// printf(format_trick1, 4294967296);
	// ft_printf("ft_printf 4294967296: ");
	// ft_printf(format_trick1, 4294967296);
	// ft_printf("\n");

	// ft_printf("printf 4294967296: ");
	// printf(format_trick2, 4294967296);
	// ft_printf("ft_printf 4294967296: ");
	// ft_printf(format_trick2, 4294967296);
	// ft_printf("\n");

	// ft_printf("printf 4294967296: ");	
	// printf(format_trick3, 4294967296);
	// ft_printf("ft_printf 4294967296: ");
	// ft_printf(format_trick3, 4294967296);
	// ft_printf("\n");

	// ft_printf("printf 4294967296: ");
	// printf(format_trick4, 4294967296);
	// ft_printf("ft_printf 4294967296: ");
	// ft_printf(format_trick4, 4294967296);
	// ft_printf("\n");

	// ft_printf("printf 0: ");
	// printf("	*%#x*\n", 0);
	// ft_printf("ft_printf 0: ");
	// ft_printf("	*%#x*\n\n", 0);

	// ft_printf("\n\n***** star (*) flag testing *****\n\n");

	// printf("printf prec 3, neg   : *%.*d*\n", 3, -25);
	// ft_printf("ft_printf prec 3, neg: *%.*d*\n\n", 3, -25);

	// printf("printf width 1   : *%*d*\n", 1, 25);
	// ft_printf("ft_printf width 1: *%*d*\n\n", 1, 25);

	// printf("printf width 10   : *%*d*\n", 10, 12345);
	// ft_printf("ft_printf width 10: *%*d*\n\n", 10, 12345);

	// printf("printf width 20   : *%*d*\n", 20, 78912340);
	// ft_printf("ft_printf width 20: *%*d*\n\n", 20, 78912340);

	// printf("printf preci 8   : *%.*d*\n", 8, 27);
	// ft_printf("ft_printf preci 8: *%.*d*\n\n", 8, 27);

	// printf("printf width 4 preci 8   : *%*.*d*\n", 4, 8, 312);
	// ft_printf("ft_printf width 4 preci 8: *%*.*d*\n\n", 4, 8, 312);

	// printf("printf width 10 precision 4   : *%*.*d*\n", 10, 4, 15);
	// ft_printf("ft_printf width 10 precision 4: *%*.*d*\n\n", 10, 4, 15);

	// printf("printf width 20 precision 6   : *%*.*d*\n", 20, 6, 234);
	// ft_printf("ft_printf width 20 precision 6: *%*.*d*\n\n", 20, 6, 234);

	// printf("printf neg width 1   : *%*d*\n", 1, -27);
	// ft_printf("ft_printf neg width 1: *%*d*\n\n", 1, -27);

	// printf("printf neg width 10   : *%*d*\n", 10, -2785);
	// ft_printf("ft_printf neg width 10: *%*d*\n\n", 10, -2785);

	// printf("printf neg width 20   : *%*d*\n", 20, -2905654);
	// ft_printf("ft_printf neg width 20: *%*d*\n\n", 20, -2905654);

	// printf("printf neg preci 8   : *%.*d*\n", 8, -3476);
	// ft_printf("ft_printf neg preci 8: *%.*d*\n\n", 8, -3476);

	// printf("printf neg width 4 preci 8   : *%*.*d*\n", 4, 8, -271);
	// ft_printf("ft_printf neg width 4 preci 8: *%*.*d*\n\n", 4, 8, -271);

	// printf("printf neg width 10 precision 4   : *%*.*d*\n", 10, 4, -3);
	// ft_printf("ft_printf neg width 10 precision 4: *%*.*d*\n\n", 10, 4, -3);

	// printf("printf neg width 20 precision 6   : *%*.*d*\n", 20, 6, -34);
	// ft_printf("ft_printf neg width 20 precision 6: *%*.*d*\n\n", 20, 6, -34);
	
	// printf("printf   : *%.*s*\n", -3, "hello");
	// ft_printf("ft_printf: *%.*s*\n\n", -3, "hello");

	// printf("printf   : *%-*.*s*\n", -7, -3, "yolo");
	// ft_printf("ft_printf: *%-*.*s*\n\n", -7, -3, "yolo");

	// printf("printf   : *%.*d*\n", -1, 0);
	// ft_printf("ft_printf: *%.*d*\n\n", -1, 0);

	// printf("printf   : *%.*u*\n", -1, 0);
	// ft_printf("ft_printf: *%.*u*\n\n", -1, 0);

	// printf("printf   : *%.*o*\n", -1, 0);
	// ft_printf("ft_printf: *%.*o*\n\n", -1, 0);

	// printf("printf   : *%.*x*\n", -1, 0);
	// ft_printf("ft_printf: *%.*x*\n\n", -1, 0);

	// printf("printf   : *%.*X*\n", -1, 0);
	// ft_printf("ft_printf: *%.*X*\n\n", -1, 0);

	// printf("printf   : *%.*s*\n", -3, NULL);
	// ft_printf("ft_printf: *%.*s*\n\n", -3, NULL);

	// printf("printf   : *%.*s*\n", -1, NULL);
	// ft_printf("ft_printf: *%.*s*\n\n", -1, NULL);

	// char *pointer_trick = "printf   : *%.*p*\n";
	// printf(pointer_trick, -3, NULL);
	// ft_printf("ft_printf: *%.*p*\n\n", -3, NULL);

	// printf(pointer_trick, -1, NULL);
	// ft_printf("ft_printf: *%.*p*\n\n", -1, NULL);

	// pointer_trick = "%20.20*d";
	// printf("printf    *");
	// printf(pointer_trick, 123);
	// printf("*\n");
	// ft_printf("ft_printf *");
	// ft_printf(pointer_trick, 123);
	// ft_printf("*\n");

	// ft_printf("\n\n***** length modifier testing *****\n\n");
	// short aShortInt       = 64;
	// char  aReallyShortInt = 64;
	// int long alongint = 12345678998765432;
	// int long long alonglongint = 123456;
	// long double alongdouble = 9999.9999999999999999;
	// long double alonglongdouble = 9999.9999999999999999999999999999999;

	// printf("printf    long length mod test: %d %ld %lld %f %Lf %hhd %Lf %hd %ld %hd %s %p %d %ld %lld %lf %Lf %hhd %Lf %hd %ld %hd %s %p  \n", 123, alongint, alonglongint, 0.999, alonglongdouble, aReallyShortInt, alongdouble, aShortInt, alongint, aShortInt, "hello", (void *)&aShortInt, 123, alongint, alonglongint, 0.999, alonglongdouble, aReallyShortInt, alongdouble, aShortInt, alongint, aShortInt, "hello", (void *)&aShortInt);
	// ft_printf("ft_printf long length mod test: %d %ld %lld %f %Lf %hhd %Lf %hd %ld %hd %s %p %d %ld %lld %lf %Lf %hhd %Lf %hd %ld %hd %s %p\n\n", 123, alongint, alonglongint, 0.999, alonglongdouble, aReallyShortInt, alongdouble, aShortInt, alongint, aShortInt, "hello", &aShortInt, 123, alongint, alonglongint, 0.999, alonglongdouble, aReallyShortInt, alongdouble, aShortInt, alongint, aShortInt, "hello", &aShortInt);

	// ft_printf("\n\n***** memory address testing *****\n\n");
	// int i = 5;
	// char *ptr2 = "hello world";
	// int k = 5;
	// int *ptr = &i;
	// int *ptr3 = &k;
	// printf("printf address test   : *%p*\n", (void *)ptr);
	// ft_printf("ft_printf address test: *%p*\n\n", (void *)ptr);

	// printf("printf    address test, width 3: *%3p*\n", (void *)ptr2);
	// ft_printf("ft_printf address test, width 3: *%3p*\n\n", ptr2);

	// printf("printf    address test, width 20: *%20p*\n", (void *)ptr3);
	// ft_printf("ft_printf address test, width 20: *%20p*\n\n", ptr3);

	// printf("printf    address test, width 20, left aligned: *%-20p*\n", (void *)ptr);
	// ft_printf("ft_printf address test, width 20, left aligned: *%-20p*\n\n", ptr);

	// printf("printf    NULL address test: *%p*\n", NULL);
	// ft_printf("ft_printf NULL address test: *%p*\n\n", NULL);

	// char *fu_compiler1 =	"printf    NULL address, 0 precision:	*%.0p*	*%.p*\n";
	// char *fu_compiler2 =	"ft_printf NULL address, 0 precision:	*%.0p*	*%.p*\n\n";
	// printf(fu_compiler1, NULL, NULL);
	// ft_printf(fu_compiler2, NULL, NULL);

	// ft_printf("\n\n***** BIG number testing *****\n\n");
	// long long int super_big = 2345678923456781234; 
	// long long int not_so_super_big = 234;
	// long long int neg_super_big = -2345678923456781234;
	// long long int neg_not_so_super_big = -234;
	// int nb = 125;
	// int neg_nb = -125567;
	// printf("printf    long long test: %lld\n", super_big);
	// ft_printf("ft_printf long long test: %lld\n\n", super_big);

	// printf("printf    long long hex test: %llx\n", super_big);
	// ft_printf("ft_printf long long hex test: %llx\n\n", super_big);

	// printf("printf    long long oct test: %llo\n", super_big);
	// ft_printf("ft_printf long long oct test: %llo\n\n", super_big);

	// printf("printf    long long test: %lld\n", not_so_super_big);
	// ft_printf("ft_printf long long test: %lld\n\n", not_so_super_big);

	// printf("printf    normal int test: %d\n", nb);
	// ft_printf("ft_printf normal int test: %d\n\n", nb);

	// printf("printf    normal neg int test: %d\n", neg_nb);
	// ft_printf("ft_printf normal neg int test: %d\n\n", neg_nb);

	// printf("printf    long long test: %lld\n", neg_super_big);
	// ft_printf("ft_printf long long test: %lld\n\n", neg_super_big);

	// printf("printf    long long test: %lld\n", neg_not_so_super_big);
	// ft_printf("ft_printf long long test: %lld\n\n", neg_not_so_super_big);

	// ft_printf("\n\n***** percent sign (%%) testing *****\n\n");

	// printf("this is what a percent sign should look like: *%%*\n");
	// ft_printf("this is what a percent sign should look like: *%%*\n\n");

	// printf("this is what a percent sign should look like, width 5: *%5%*\n");
	// ft_printf("this is what a percent sign should look like, width 5: *%5%*\n\n");

	// printf("this is what a percent sign should look like, precision 5: *%.5%*\n");
	// ft_printf("this is what a percent sign should look like, precision 5: *%.5%*\n\n");

	// printf("this is what a percent sign should look like, space flag: *% %*\n");
	// ft_printf("this is what a percent sign should look like, space flag: *% %*\n\n");
	
	// printf("this is what a percent sign should look like, plus flag: *%+%*\n");
	// ft_printf("this is what a percent sign should look like, plus flag: *%+%*\n\n");

	// printf("this is what a percent sign should look like, minus (left align) flag, width 10: *%-10%*\n");
	// ft_printf("this is what a percent sign should look like, minus (left align) flag, width 10: *%-10%*\n\n");

	// printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%d%-10%*\n", 123);
	// ft_printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%d%-10%*\n\n", 123);
	
	// printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%-10d%%*\n", 123);
	// ft_printf("this is what a percent sign should look like next to an int, minus (left align) flag, width 10: *%-10d%%*\n\n", 123);
	
	// printf("percent with a 0 flag and width 10 (undefined behaviour): *%010%*\n");
	// ft_printf("percent with a 0 flag and width 10 (undefined behaviour): *%010%*\n\n");

	// ft_printf("\n\n***** space (' ') flag testing *****\n\n");
	// printf("printf space test   : *% d*\n", 25);
	// ft_printf("ft_printf space test: *% d*\n\n", 25);

	// printf("printf space test, neg int   : *% d*\n", -25);
	// ft_printf("ft_printf space test, neg int: *% d*\n\n", -25);

	// printf("printf space test, width 2   : *% 2d*\n", 25);
	// ft_printf("ft_printf space test, width 2: *% 2d*\n\n", 25);

	// printf("printf space test (width 10, precision 6)   : *% 10.6d*\n", 257);
	// ft_printf("ft_printf space test (width 10, precision 6): *% 10.6d*\n\n", 257);

	// printf("printf space test (width 6, precision 6)   : *% 6.6d*\n", 1234);
	// ft_printf("ft_printf space test (width 6, precision 6): *% 6.6d*\n\n", 1234);

	// printf("printf space test (width 5, precision 6)   : *% 5.6d*\n", 4321);
	// ft_printf("ft_printf space test (width 5, precision 6): *% 5.6d*\n\n", 4321);

	// printf("printf space and 0 test (width 10)   : *% 010d*\n", 2727);
	// ft_printf("ft_printf space and 0 test (width 10): *% 010d*\n\n", 2727);
	
	// ft_printf("\n\n***** plus (+) flag testing *****\n\n");
	// printf("printf plus test   : *%+d*\n", 25);
	// ft_printf("ft_printf plus test: *%+d*\n\n", 25);

	// printf("printf plus test, neg int   : *%+d*\n", -25);
	// ft_printf("ft_printf plus test, neg int: *%+d*\n\n", -25);

	// printf("printf plus test, width 2   : *%+2d*\n", 27);
	// ft_printf("ft_printf plus test, width 2: *%+2d*\n\n", 27);

	// printf("printf plus test (width 10, precision 6)   : *%+10.6d*\n", 2734);
	// ft_printf("ft_printf plus test (width 10, precision 6): *%+10.6d*\n\n", 2734);

	// printf("printf plus test (width 6, precision 6)   : *%+6.6d*\n", 123);
	// ft_printf("ft_printf plus test (width 6, precision 6): *%+6.6d*\n\n", 123);

	// printf("printf plus test (width 5, precision 6)   : *%+5.6d*\n", 432);
	// ft_printf("ft_printf plus test (width 5, precision 6): *%+5.6d*\n\n", 432);

	// printf("printf plus and 0 test (width 10)   : *%+010d*\n", 789);
	// ft_printf("ft_printf plus and 0 test (width 10): *%+010d*\n", 789);
	
	// ft_printf("\n\n***** zero (0) flag testing *****\n\n");
	// char *format_bypass = "0 flag with decimal (width 10), left aligned: *%-010d*\n";
	// printf("printf 0 flag with decimal (no width):    *%0d*\n", 123);
	// ft_printf("ft_printf 0 flag with decimal (no width): *%0d*\n\n", 123);
	// printf("printf 0 flag with decimal (width 10):    *%010d*\n", 123);
	// ft_printf("ft_printf 0 flag with decimal (width 10): *%010d*\n\n", 123);
	// printf("printf    ");
	// printf(format_bypass, 123);
	// ft_printf("ft_printf ");
	// ft_printf(format_bypass, 123);
	// ft_printf("\n");
	// printf("printf 0 flag with octal (width 10):    *%010o*\n", 123);
	// ft_printf("ft_printf 0 flag with octal (width 10): *%010o*\n\n", 123);
	// printf("printf 0 flag with octal (width 3):    *%03o*\n", 123);
	// ft_printf("ft_printf 0 flag with octal (width 3): *%03o*\n\n", 123);
	// printf("printf 0 flag with hexadecimal (width 10):    *%010x*\n", 123);
	// ft_printf("ft_printf 0 flag with hexadecimal (width 10): *%010x*\n\n", 123);
	// printf("printf 0 flag with hexadecimal and hash (width 10):    *%0#10x*\n", 123);
	// ft_printf("ft_printf 0 flag with hexadecimal and hash (width 10): *%0#10x*\n\n", 123);
	// printf("printf 0 flag with upper hexadecimal and hash (width 10):    *%0#10X*\n", 123123);
	// ft_printf("ft_printf 0 flag with upper hexadecimal and hash (width 10): *%0#10X*\n\n", 123123);

	// ft_printf("\n\n***** hash flag testing *****\n\n");
	// printf("printf hash flag with octal   : *%#o*\n", 7981);
	// ft_printf("ft_printf hash flag with octal: *%#o*\n\n", 7981);
	// printf("printf hash flag with hex   : *%#x*\n", 432);
	// ft_printf("ft_printf hash flag with hex: *%#x*\n\n", 432);
	// printf("printf hash flag with upper hex   : *%#X*\n", 123123);
	// ft_printf("ft_printf hash flag with upper hex: *%#X*\n\n", 123123);
	// printf("printf hash flag with octal and with 10   : *%#10o*\n", 980);
	// ft_printf("ft_printf hash flag with octal and with 10: *%#10o*\n\n", 980);
	// printf("printf hash flag with hex and with 10   : *%#10x*\n", 789123);
	// ft_printf("ft_printf hash flag with hex and with 10: *%#10x*\n\n", 789123);
	// printf("printf hash flag with upper hex and with 10   : *%#10X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex and with 10: *%#10X*\n\n", 234);
	// printf("printf hash flag with upper hex and with 10 and precision 6   : *%#10.6X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex and with 10 and precision 6: *%#10.6X*\n\n", 234);
	// printf("printf hash flag with upper hex and with 10 and precision blank   : *%#10.X*\n", 234);
	// ft_printf("ft_printf hash flag with upper hex and with 10 and precision blank: *%#10.X*\n\n", 234);

	// printf("printf hash flag with upper hex 0 and with 10 and precision blank, val 0   : *%#10.X*\n", 0);
	// ft_printf("ft_printf hash flag with upper hex 0 and with 10 and precision blank, val 0: *%#10.X*\n\n", 0);


	// printf("printf no flag with upper hex and with 10 and precision blank   : *%10.X*\n", 234);
	// ft_printf("ft_printf no flag with upper hex and with 10 and precision blank: *%10.X*\n\n", 234);

	// printf("printf no flag with upper hex and with 10 and precision 0   : *%10.0X*\n", 234);
	// ft_printf("ft_printf no flag with upper hex and with 10 and precision 0: *%10.0X*\n\n", 234);

	
	// printf("printf no flag with decimal 0 and with 10 and precision 0   : *%10.0d*\n", 0);
	// ft_printf("ft_printf no flag with decimal 0 and with 10 and precision 0: *%10.0d*\n\n", 0);
	// printf("printf no flag with octal 0 and with 10 and precision 0   : *%10.0o*\n", 0);
	// ft_printf("ft_printf no flag with octal 0 and with 10 and precision 0: *%10.0o*\n\n", 0);
	// printf("printf no flag with decimal 0 and no width and precision 0   : *%.0d*\n", 0);
	// ft_printf("ft_printf no flag with decimal 0 and no width and precision 0: *%.0d*\n\n", 0);

	// printf("printf with upper hex and with 10 and precision 6   : *%10.6X*\n", 789);
	// ft_printf("ft_printf with upper hex and with 10 and precision 6: *%10.6X*\n\n", 789);
	// printf("printf hash flag with octal and with 10 and precision 6   : *%#10.6o*\n", 543);
	// ft_printf("ft_printf hash flag with octal and with 10 and precision 6: *%#10.6o*\n\n", 543);




	// ft_printf("\n\n***** precision and width testing *****\n\n");


	// printf("printf prec 3, neg   : *%.3d*\n", -25);
	// ft_printf("ft_printf prec 3, neg: *%.3d*\n\n", -25);

	// printf("printf width 1   : *%1d*\n", 25);
	// ft_printf("ft_printf width 1: *%1d*\n\n", 25);

	// printf("printf width 10   : *%10d*\n", 12345);
	// ft_printf("ft_printf width 10: *%10d*\n\n", 12345);


	// printf("printf width 20   : *%20d*\n", 78912340);
	// ft_printf("ft_printf width 20: *%20d*\n\n", 78912340);

	// printf("printf preci 8   : *%.8d*\n", 27);
	// ft_printf("ft_printf preci 8: *%.8d*\n\n", 27);

	// char *test_str = "%.-8d";
	// printf("printf preci -8   : *"),
	// printf(test_str, 27);
	// printf("*\n");

	// ft_printf("ft_printf preci -8: *");
	// ft_printf(test_str, 27);
	// ft_printf("*\n\n");

	// char *test_str2 = "%.-1d";
	// printf("printf preci -1   : *"),
	// printf(test_str2, 27);
	// printf("*\n");

	// ft_printf("ft_printf preci -1: *");
	// ft_printf(test_str2, 27);
	// ft_printf("*\n\n");


	// printf("printf width 4 preci 8   : *%4.8d*\n", 312);
	// ft_printf("ft_printf width 4 preci 8: *%4.8d*\n\n", 312);

	// printf("printf width 10 precision 4   : *%10.4d*\n", 15);
	// ft_printf("ft_printf width 10 precision 4: *%10.4d*\n\n", 15);

	// printf("printf width 10 precision 04   : *%10.04d*\n", 15);
	// ft_printf("ft_printf width 10 precision 04: *%10.04d*\n\n", 15);
	// printf("printf precision 04   : *%.04d*\n", 15);
	// ft_printf("ft_printf precision 04: *%.04d*\n\n", 15);

	// printf("printf width 20 precision 6   : *%20.6d*\n", 234);
	// ft_printf("ft_printf width 20 precision 6: *%20.6d*\n\n", 234);

	// printf("printf neg width 1   : *%1d*\n", -27);
	// ft_printf("ft_printf neg width 1: *%1d*\n\n", -27);

	// printf("printf neg width 10   : *%10d*\n", -2785);
	// ft_printf("ft_printf neg width 10: *%10d*\n\n", -2785);

	// printf("printf neg width 20   : *%20d*\n", -2905654);
	// ft_printf("ft_printf neg width 20: *%20d*\n\n", -2905654);

	// printf("printf neg preci 8   : *%.8d*\n", -3476);
	// ft_printf("ft_printf neg preci 8: *%.8d*\n\n", -3476);

	// printf("printf neg width 4 preci 8   : *%4.8d*\n", -271);
	// ft_printf("ft_printf neg width 4 preci 8: *%4.8d*\n\n", -271);

	// printf("printf neg width 10 precision 4   : *%10.4d*\n", -3);
	// ft_printf("ft_printf neg width 10 precision 4: *%10.4d*\n\n", -3);

	// printf("printf neg width 20 precision 6   : *%20.6d*\n", -34);
	// ft_printf("ft_printf neg width 20 precision 6: *%20.6d*\n\n", -34);

	// printf("printf precision 6, left aligned   : *%-.6d*\n", 212);
	// ft_printf("ft_printf precision 6, left aligned: *%-.6d*\n\n", 212);

	// printf("printf precision 6, width 6   : *%6.6d*\n", 765);
	// ft_printf("ft_printf precision 6, width 6: *%6.6d*\n\n", 765);

	// printf("printf precision 6, width 7 left aligned   : *%-7.6d*\n", 341);
	// ft_printf("ft_printf precision 6, width 7 left aligned: *%-7.6d*\n\n", 341);

	// printf("printf width 20 precision 6, left aligned   : *%-20.6d*\n", 129856);
	// ft_printf("ft_printf width 20 precision 6, left aligned: *%-20.6d*\n\n", 129856);

	// printf("printf neg precision 6, left aligned   : *%-.6d*\n", -212);
	// ft_printf("ft_printf neg precision 6, left aligned: *%-.6d*\n\n", -212);

	// printf("printf neg precision 6, width 6   : *%6.6d*\n", -765);
	// ft_printf("ft_printf neg precision 6, width 6: *%6.6d*\n\n", -765);

	// printf("printf neg precision 6, width 7 left aligned   : *%-7.6d*\n", -341);
	// ft_printf("ft_printf neg precision 6, width 7 left aligned: *%-7.6d*\n\n", -341);

	// printf("printf neg width 20 precision 6, left aligned   : *%-20.6d*\n", -129856);
	// ft_printf("ft_printf neg width 20 precision 6, left aligned: *%-20.6d*\n\n", -129856);

	// printf("printf unsigned neg precision 6, width 6   : *%6.6u*\n", -765);
	// ft_printf("ft_printf unsigned neg precision 6, width 6: *%6.6u*\n\n", -765);

	// printf("printf unsigned neg precision 6, width 7 left aligned   : *%-7.6u*\n", -341);
	// ft_printf("ft_printf unsigned neg precision 6, width 7 left aligned: *%-7.6u*\n\n", -341);

	// printf("printf unsigned neg width 20 precision 6, left aligned   : *%-20.6u*\n", -129856);
	// ft_printf("ft_printf unsigned neg width 20 precision 6, left aligned: *%-20.6u*\n\n", -129856);

	// printf("printf unsigned precision 6, width 6   : *%6.6u*\n", 765);
	// ft_printf("ft_printf unsigned precision 6, width 6: *%6.6u*\n\n", 765);

	// printf("printf unsigned precision 6, width 7 left aligned   : *%-7.6u*\n", 341);
	// ft_printf("ft_printf unsigned precision 6, width 7 left aligned: *%-7.6u*\n\n", 341);

	// printf("printf unsigned width 20 precision 6, left aligned   : *%-20.6u*\n", 129856);
	// ft_printf("ft_printf unsigned width 20 precision 6, left aligned: *%-20.6u*\n\n", 129856);
	// printf("printf string test width 20   : *%20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20: *%20s*\n\n", "hello world");
	// printf("printf string test width 20, left aligned   : *%-20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20, left aligned: *%-20s*\n\n", "hello world");
	// printf("printf string test width 20 precision 20   : *%20.20s*\n", "hello world");
	// ft_printf("ft_printf string test width 20 precision 20: *%20.20s*\n\n", "hello world");
	// printf("printf string test precision 20   : *%.20s*\n", "hello world");
	// ft_printf("ft_printf string test precision 20: *%.20s*\n\n", "hello world");
	// compiler_trick = "printf char test precision 20   : *%.20c*\n";
	// printf(compiler_trick, 'c');
	// ft_printf("ft_printf char test precision 20: *%.20c*\n\n", 'c');
	// printf("printf hex test width 20 precision 20   : *%20.20x*\n", 1234);
	// ft_printf("ft_printf hex test width 20 precision 20: *%20.20x*\n\n", 1234);
	// printf("printf oct test width 20 precision 20   : *%20.20o*\n", 1234);
	// ft_printf("ft_printf oct test width 20 precision 20: *%20.20o*\n\n", 1234);


	// ft_printf("\n***** octal conversions *****\n\n");
	// ft_printf("ft_printf octal: %o\n", 5);
	// printf("printf octal   : %o\n", 5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 512);
	// printf("printf octal   : %o\n", 512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 7000003);
	// printf("printf octal   : %o\n", 7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 916);
	// printf("printf octal   : %o\n", 916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf octal: %o\n", 24);
	// printf("printf octal   : %o\n", 24);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg octal: %o\n", -5);
	// printf("printf neg octal   : %o\n", -5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg octal: %o\n", -512);
	// printf("printf neg octal   : %o\n", -512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg octal: %o\n", -7000003);
	// printf("printf neg octal   : %o\n", -7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg octal: %o\n", -916);
	// printf("printf neg octal   : %o\n", -916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg octal: %o\n", -24);
	// printf("printf neg octal   : %o\n", -24);
	
	// ft_printf("\n\n***** hexadecimal conversions *****\n\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 5);
	// printf("printf hexadecimal   : %x\n", 5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 512);
	// printf("printf hexadecimal   : %x\n", 512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf hexadecimal: %x\n", 7000003);
	// printf("printf hexadecimal   : %x\n", 7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf uppercase hexadecimal: %X\n", 1916);
	// printf("printf uppercase hexadecimal   : %X\n", 1916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf uppercase hexadecimal: %X\n", 10527024);
	// printf("printf uppercase hexadecimal   : %X\n", 10527024);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg hexadecimal: %x\n", -5);
	// printf("printf neg hexadecimal   : %x\n", -5);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg hexadecimal: %x\n", -512);
	// printf("printf neg hexadecimal   : %x\n", -512);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg hexadecimal: %x\n", -7000003);
	// printf("printf neg hexadecimal   : %x\n", -7000003);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg uppercase hexadecimal: %X\n", -1916);
	// printf("printf neg uppercase hexadecimal   : %X\n", -1916);
	// ft_printf("\n---------\n");
	// ft_printf("ft_printf neg uppercase hexadecimal: %X\n", -10527024);
	// printf("printf neg uppercase hexadecimal   : %X\n", -10527024);

	// char *str = "...and this is a string in a variable";
	// char a = 'a';
	// ft_printf("\nstring/char conversions:\n\n");
	// ft_printf("\nft_printf string: %s || %s\n", "hello world", str);
	// printf("printf string   : %s || %s\n", "hello world", str);
	// ft_printf("\n---------\n");
	// ft_printf("\nft_printf string: %s || %s || check digits still work: %d\n", "hello world", str, 123);
	// printf("printf string   : %s || %s || check digits still work: %d\n", "hello world", str, 123);
	// ft_printf("\n---------\n");
	// ft_printf("\nft_printf char: %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	// printf("printf char   : %c || %s %c || check digits still work: %d\n", 'a', "this is a char variable:", a, 123);
	// ft_printf("\n---------\n");
	// printf("\nprintf    char test with number outside of ASCII range: %c\n", 312);
	// ft_printf("ft_printf char test with number outside of ASCII range: %c\n\n", 312);
	// printf("\nprintf    char test with NULL char: *%c*\n", 0);
	// ft_printf("ft_printf char test with NULL char: *%c*\n\n", 0);
	// printf("\nprintf    char test with NULL char, width 5: *%5c*\n", 0);
	// ft_printf("ft_printf char test with NULL char, width 5: *%5c*\n\n", 0);
	// printf("printf    null str *%s* %s\n", NULL, "and text");
	// ft_printf("ft_printf null str *%s* %s\n\n", NULL, "and text");
	// printf("printf    'hello world' str precision 3 *%.3s*\n", "hello world");
	// ft_printf("ft_printf 'hello world' str precision 3 *%.3s*\n\n", "hello world");
	// printf("printf    null str precision 3 *%.3s*\n", NULL);
	// ft_printf("ft_printf null str precision 3 *%.3s*\n\n", NULL);

	// printf("printf    null *%c* and text\n", 0);
	// ft_printf("ft_printf null *%c* and text\n\n", 0);

	// printf("printf    'hello world' and percent *%%%s*\n", "hello world");
	// ft_printf("ft_printf 'hello world' and percent *%%%s*\n\n", "hello world");
	return (0);
}
