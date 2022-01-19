/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/19 13:18:47 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	add_numbers(int n, ...)
{
	int sum = 0;
	
	va_list ptr;	
	va_start(ptr, n);
	for (int i = 0; i < n; i++)
		sum += va_arg(ptr, int);
	va_end(ptr);
	return (sum);
}

int	ft_printf(char *s, ...)
{
	//va_list ptr;
	//va_start(ptr, s);
	for (int i = 0; s[i] != '\0'; i++)
		write(1, &s[i], 1);
	//va_end(ptr);
	return (0);
}

int main(void)
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
	ft_printf("hello world\n");
	return (0);
}