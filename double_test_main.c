/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_test_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:17:33 by amann             #+#    #+#             */
/*   Updated: 2022/02/07 15:03:44 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// must handle flags 'l' (long / unsigned long) and 'L' (long double)
// doubles return 6 dec places by default.
// non-floating point numbers return compiler warning and 0.000000 

// f (double) has 15 dp precision, Lf(long double), has

int main(void)
{
	double x = 123;
	double neg_x = -123;
	double x_point_3 = 123.456;
	ft_printf("\n\n ***** FLOAT TESTS ***** \n\n");
	printf("printf integer test   :%f\n", x);
	ft_printf("ft_printf integer test:%f\n\n", x);
	
	printf("printf neg integer test   :%f\n", neg_x);
	ft_printf("ft_printf neg integer test:%f\n\n", neg_x);

	printf("printf neg double test   :%f\n", neg_x * 2); 
	ft_printf("ft_printf neg double test:%f\n\n", neg_x * 2);

	printf("printf double no prec test   :%f\n", x_point_3);
	ft_printf("ft_printf double no prec test:%f\n\n", x_point_3);

	printf("printf double prec 3 test   :%.3f\n", x_point_3);
	ft_printf("ft_printf double prec 3 test:%.3f\n\n", x_point_3);

	printf("printf double prec 10 test   :%.10f\n", x_point_3);
	ft_printf("ft_printf double prec 10 test:%.10f\n\n", x_point_3);

	printf("printf double prec 1 test   :%.1f\n", x_point_3);
	ft_printf("ft_printf double prec 1 test:%.1f\n\n", x_point_3);

	printf("printf double prec 0 test   :%.0f\n", x_point_3);
	ft_printf("ft_printf double prec 0 test:%.0f\n\n", x_point_3);

	printf("printf double no prec 10dp rounding test   :%f\n", 123.4567898234);
	ft_printf("ft_printf double no prec 10dp rounding test:%f\n\n", 123.4567898234);

	printf("printf double no prec 10dp no rounding test   :%f\n", 123.4567891234);
	ft_printf("ft_printf double no prec 10dp no rounding test:%f\n\n", 123.4567891234);

	printf("printf double prec 15 no flag test   :%.15f\n", 0.123456789123456789);
	ft_printf("ft_printf double prec 15 no flag test:%.15f\n\n", 0.123456789123456789);

	printf("printf double prec 15 l flag test   :%.15lf\n", 0.123456789123456789);
	ft_printf("ft_printf double prec 15 l flag test:%.15lf\n\n", 0.123456789123456789);
	
	long double F = 3.14;
	long double F2 = 3.123456789;
	printf("printf double no prec L flag test   :%Lf\n", F);
	ft_printf("ft_printf double no prec L flag test:%Lf\n\n", F);

	printf("printf double prec 20 L flag test   :%.20Lf\n", F);
	ft_printf("ft_printf double prec 20 L flag test:%.20Lf\n\n", F);

	printf("printf double prec 20 L flag test   :%.20Lf\n", F2);
	ft_printf("ft_printf double prec 20 L flag test:%.20Lf\n\n", F2);


	return (0);
}