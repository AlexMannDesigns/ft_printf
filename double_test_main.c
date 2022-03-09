/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_test_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 11:17:33 by amann             #+#    #+#             */
/*   Updated: 2022/03/09 16:22:45 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// must handle flags 'l' (long / unsigned long) and 'L' (long double)
// doubles return 6 dec places by default.
// non-floating point numbers return compiler warning and 0.000000 

// f (double) has 15 dp precision, Lf(long double), has

int main(void)
{
	// double x = 123;
	// double neg_x = -123;
	// double x_point_3 = 123.456;
	ft_printf("\n\n ***** FLOAT TESTS ***** \n\n");

	printf("printf plus and zero test:    %+010.5f\n", 1122.2);
	ft_printf("ft_printf plus and zero test: %+010.5f\n\n", 1122.2);

	// printf("printf 0.0 and -0.0 test   : *%f* *%f*\n", 0.0, -0.0);
	// ft_printf("ft_printf 0.0 and -0.0 test: *%f* *%f*\n\n", 0.0, -0.0);

	// printf("printf rounding test:    %.f %.f %.f %.f %.f %.f %.f %.f %.f %.f\n", 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);
	// ft_printf("ft_printf rounding test: %.f %.f %.f %.f %.f %.f %.f %.f %.f %.f\n\n", 0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5);

	// printf("printf rounding test:    %.f %.f %.f %.f %.f %.f %.f %.f\n", 1000.5, 1001.5, 1002.5, 1003.5, 1004.5, 1005.5, 999.5, 998.5);
	// ft_printf("ft_printf rounding test: %.f %.f %.f %.f %.f %.f %.f %.f\n\n", 1000.5, 1001.5, 1002.5, 1003.5, 1004.5, 1005.5, 999.5, 998.5);

	// printf("printf rounding test:     %.f %.f %.f %.3f %.3f %.5f %.8f %.10f %.1f %.f\n", 0.54,  0.5000000000000001, 0.556500, 0.5595, 0.5585, 1.5555555555555, 2.5555555555555, 3.5555555555555, 4.5555555555555, 5.5555555555555);
	// ft_printf("ft_printf rounding test:  %.f %.f %.f %.3f %.3f %.5f %.8f %.10f %.1f %.f\n\n", 0.54, 0.5000000000000001, 0.556500, 0.5595, 0.5585, 1.5555555555555, 2.5555555555555, 3.5555555555555, 4.5555555555555, 5.5555555555555);
	
	// printf("printf 0.0 test   :			*%f*\n", 0.0);
	// ft_printf("ft_printf 0.0 test:			*%f*\n\n", 0.0);

	// printf("printf 0.000001 test   :		*%f*\n", 0.000001);
	// ft_printf("ft_printf 0.000001 test:		*%f*\n\n", 0.000001);

	// printf("printf 0.000000001 test   :		*%f*\n", 0.000000001);
	// ft_printf("ft_printf 0.000000001 test:		*%f*\n\n", 0.000000001);

	// printf("printf 0.000000001 test, prec 20   :	*%.20f*\n", 0.000000001);
	// ft_printf("ft_printf 0.000000001 test, prec 20:	*%.20f*\n\n", 0.000000001);

	// printf("printf 0.000501 test   :		*%f*\n", 0.000501);
	// ft_printf("ft_printf 0.000501 test:		*%f*\n\n", 0.000501);

	// printf("printf 0.000401 test   :		*%f*\n", 0.000401);
	// ft_printf("ft_printf 0.000401 test:		*%f*\n\n", 0.000401);
	
	// printf("printf 9127894567.000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.000478621531L);
	// ft_printf("ft_printf 9127894567.000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.000478621531L);

	// printf("printf 9127894567.0000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.0000478621531L);
	// ft_printf("ft_printf 9127894567.0000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.0000478621531L);

	// printf("printf 9127894567.00000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.00000478621531L);
	// ft_printf("ft_printf 9127894567.00000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.00000478621531L);
	
	// printf("printf 9127894567.000000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.000000478621531L);
	// ft_printf("ft_printf 9127894567.000000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.000000478621531L);

	// printf("printf 9127894567.0000000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.0000000478621531L);
	// ft_printf("ft_printf 9127894567.0000000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.0000000478621531L);

	// printf("printf 9127894567.00000000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.00000000478621531L);
	// ft_printf("ft_printf 9127894567.00000000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.00000000478621531L);

	// printf("printf 9127894567.000000000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.000000000478621531L);
	// ft_printf("ft_printf 9127894567.000000000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.000000000478621531L);
	
	// printf("printf 9127894567.0000000000478621531 test, prec 30, L flag   :	*%.30Lf*\n", 9127894567.0000000000478621531L);
	// ft_printf("ft_printf 9127894567.0000000000478621531 test, prec 30, L flag:	*%.30Lf*\n\n", 9127894567.0000000000478621531L);


	// printf("printf integer 1 test   :	*%f*\n", 1.0);
	// ft_printf("ft_printf integer 1 test:	*%f*\n\n", 1.0);
	
	// printf("printf integer 1.7 test   :	*%f*\n", 1.7);
	// ft_printf("ft_printf integer 1.7 test:	*%f*\n\n", 1.7);
	
	// printf("printf integer 1.7 test, prec 0   :	*%.0f*\n", 1.7);
	// ft_printf("ft_printf integer 1.7 test, prec 0:	*%.0f*\n\n", 1.7);

	// printf("printf integer 9999.99999 test, prec 0   :	*%.0f*\n", 9999.99999);
	// ft_printf("ft_printf integer 9999.99999 test, prec 0:	*%.0f*\n\n", 9999.99999);

	// printf("printf integer 999999999.999999999999 test, prec 10   :	*%.10f*\n", 999999999.999999999999);
	// ft_printf("ft_printf integer 999999999.999999999999 test, prec 10:	*%.10f*\n\n", 999999999.999999999999);
	
	// printf("printf integer 0.9 test   :			*%f*\n", 0.9);
	// ft_printf("ft_printf integer 0.9 test:			*%f*\n\n", 0.9);
	
	// printf("printf integer 0.999999 test   :		*%f*\n", 0.999999);
	// ft_printf("ft_printf integer 0.999999 test:		*%f*\n\n", 0.999999);

	// printf("printf integer 0.999999 test, prec 3   :	*%.3f*\n", 0.999999);
	// ft_printf("ft_printf integer 0.999999 test, prec 3:	*%.3f*\n\n", 0.999999);

	// printf("printf integer 0.999999999999 test, prec 10   :	*%.10f*\n", 0.999999999999);
	// ft_printf("ft_printf integer 0.999999999999 test, prec 10:	*%.10f*\n\n", 0.999999999999);
	
	// printf("printf integer test   :		*%f*\n", x);
	// ft_printf("ft_printf integer test:		*%f*\n\n", x);
	
	// printf("printf neg integer test   :	*%f*\n", neg_x);
	// ft_printf("ft_printf neg integer test:	*%f*\n\n", neg_x);

	// printf("printf neg double test   :	*%f*\n", neg_x * 2); 
	// ft_printf("ft_printf neg double test:	*%f*\n\n", neg_x * 2);

	// printf("printf integer -999999999.999999999999 test, prec 10   :	*%.10f*\n", -999999999.999999999999);
	// ft_printf("ft_printf integer -999999999.999999999999 test, prec 10:	*%.10f*\n\n", -999999999.999999999999);

	// printf("printf double no prec 10dp neg rounding test   :	*%f*\n", -123.4567898234);
	// ft_printf("ft_printf double no prec 10dp neg rounding test:	*%f*\n\n", -123.4567898234);

	// printf("printf double no prec test   :		*%f*\n", x_point_3);
	// ft_printf("ft_printf double no prec test:		*%f*\n\n", x_point_3);

	// printf("printf double prec 3 test   :		*%.3f*\n", x_point_3);
	// ft_printf("ft_printf double prec 3 test:		*%.3f*\n\n", x_point_3);

	// printf("printf double prec 10 test   :		*%.10f*\n", x_point_3);
	// ft_printf("ft_printf double prec 10 test:		*%.10f*\n\n", x_point_3);

	// printf("printf double prec 1 test   :		*%.1f*\n", x_point_3);
	// ft_printf("ft_printf double prec 1 test:		*%.1f*\n\n", x_point_3);

	// printf("printf double prec 0 test   :		*%.0f*\n", x_point_3);
	// ft_printf("ft_printf double prec 0 test:		*%.0f*\n\n", x_point_3);

	// printf("printf double prec blank test   :	*%.f*\n", x_point_3);
	// ft_printf("ft_printf double prec blank test:	*%.f*\n\n", x_point_3);

	// printf("printf double prec blank test   :	*%.f*\n", 123.5);
	// ft_printf("ft_printf double prec blank test:	*%.f*\n\n", 123.5);


	// printf("printf double no prec 10dp rounding test   :	*%f*\n", 123.4567898234);
	// ft_printf("ft_printf double no prec 10dp rounding test:	*%f*\n\n", 123.4567898234);

	// printf("printf double no prec 10dp no rounding test   :	*%f*\n", 123.4567891234);
	// ft_printf("ft_printf double no prec 10dp no rounding test:	*%f*\n\n", 123.4567891234);
	
	// printf("printf double no prec 10dp no rounding test   :	*%f*\n", 123.459999999999);
	// ft_printf("ft_printf double no prec 10dp no rounding test:	*%f*\n\n", 123.459999999999);

	// printf("printf double prec 15 no flag test   :	*%.15f*\n", 0.123456789123456789);
	// ft_printf("ft_printf double prec 15 no flag test:	*%.15f*\n\n", 0.123456789123456789);

	// printf("printf double prec 15 no flag test   :	*%.15f*\n", 123456789.123456789123456789);
	// ft_printf("ft_printf double prec 15 no flag test:	*%.15f*\n\n", 123456789.123456789123456789);

	// printf("printf double prec 15 l flag test   :	*%.15lf*\n", 0.123456789123456789);
	// ft_printf("ft_printf double prec 15 l flag test:	*%.15lf*\n\n", 0.123456789123456789);
	
	// long double F = 3.14;
	// long double F2 = 3.123456789;
	// long double negF2 = -3.123456789;
	// long double F3 = 999999999.999999999999;
	// printf("printf double no prec L flag test   :	*%Lf*\n", F);
	// ft_printf("ft_printf double no prec L flag test:	*%Lf*\n\n", F);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", F);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", F);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", F2);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", F2);

	// printf("printf double no prec L flag test   :	*%Lf*\n", F3);
	// ft_printf("ft_printf double no prec L flag test:	*%Lf*\n\n", F3);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", F3);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", F3);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", F3);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", F3);

	// printf("printf double no prec L flag test   :	*%Lf*\n", negF2);
	// ft_printf("ft_printf double no prec L flag test:	*%Lf*\n\n", negF2);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", negF2);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", negF2);

	// printf("printf double prec 20 L flag test   :	*%.20Lf*\n", negF2);
	// ft_printf("ft_printf double prec 20 L flag test:	*%.20Lf*\n\n", negF2);

	// printf("printf double prec 30 L flag test   :	*%.30Lf*\n", negF2);
	// ft_printf("ft_printf double prec 30 L flag test:	*%.30Lf*\n\n", negF2);

	// printf("printf integer 1.7 test, width 10   :	*%10f*\n", 1.7);
	// ft_printf("ft_printf integer 1.7 test, width 10:	*%10f*\n\n", 1.7);
	
	// printf("printf integer 1.7 test, prec 0, width 10, left aligned   :		*%-10.0f*\n", 1.7);
	// ft_printf("ft_printf integer 1.7 test, prec 0, width 10, left aligned:		*%-10.0f*\n\n", 1.7);

	// printf("printf integer 9999.99999 test, prec 0, width 1   :			*%1.0f*\n", 9999.99999);
	// ft_printf("ft_printf integer 9999.99999 test, prec 0, width 1:			*%1.0f*\n\n", 9999.99999);

	// printf("printf integer 999999999.999999999999 test, prec 10, width 30   :	*%30.10f*\n", 999999999.999999999999);
	// ft_printf("ft_printf integer 999999999.999999999999 test, prec 10, width 30:	*%30.10f*\n\n", 999999999.999999999999);

	// printf("printf integer -1.7 test, width 8   :	*%8f*\n", -1.7);
	// ft_printf("ft_printf integer -1.7 test, width 8:	*%8f*\n\n", -1.7);

	// printf("printf integer -1.7 test, width 9   :	*%9f*\n", -1.7);
	// ft_printf("ft_printf integer -1.7 test, width 9:	*%9f*\n\n", -1.7);
	
	// printf("printf integer -1.7 test, width 10   :	*%10f*\n", -1.7);
	// ft_printf("ft_printf integer -1.7 test, width 10:	*%10f*\n\n", -1.7);
	return (0);
}
