/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/18 14:36:23 by amann            ###   ########.fr       */
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
	printf("this is a width test%10d!\n", 123);
	printf("this is a precision & width test %10.5d\n", 123);
	printf("\n3 + 4 + 5 + 6 = %d\n", add_numbers(4, 3, 4, 5, 6));
	ft_printf("hello world\n");
	return (0);
}