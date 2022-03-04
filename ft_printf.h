/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/03/04 11:36:01 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/***** HEADER FILES *****/

# include "libft/libft.h"
# include <stdarg.h>
# include <limits.h>

/* needed for testing */
# include <stdio.h> 

/***** MACROS *****/

# define TRUE 1
# define FALSE 0
# define ZERO_LONG_DOUBLE 0.0L
# define BASE_TWO 2
# define BASE_TEN 10
# define BASE_EIGHT 8
# define BASE_SIXTEEN 16
# define SPACE 32

/***** STRUCT PROTOTYPING *****/

typedef struct s_width
{
	int				prec;
	int				width;
	unsigned int	prec_set;
}					t_width;

typedef struct s_conv
{
	unsigned int	percent;
	unsigned int	numeric;
	unsigned int	neg;
	unsigned int	d;
	unsigned int	o;
	unsigned int	u;
	unsigned int	x;
	unsigned int	big_x;
	unsigned int	f;
	unsigned int	b;
	unsigned int	p;
	unsigned int	c;
	unsigned int	s;
}					t_conv;

typedef struct s_flags
{
	unsigned int	h;
	unsigned int	hh;
	unsigned int	l;
	unsigned int	ll;
	unsigned int	big_l;
	unsigned int	hash;
	unsigned int	zero;
	unsigned int	nil;
	unsigned int	left;
	unsigned int	plus;
	unsigned int	space;
	unsigned int	star; //maybe not needed
	t_conv			conv;
	t_width			width;
}					t_flags;

/***** FUNCTION PROTOTYPING *****/

/* ft_printf.c */
int			ft_printf(char *s, ...);

/* set_flags.c */
void		set_flags_and_length(char *s, t_flags *flag, int *h_i);
void		initialise_structs(t_flags *flag);

/* width_precision.c */
void		set_width_precision(char *s, t_flags *data, int *helper_i,		\
				 va_list lst);

/* conversion_control.c */
char		*conversion_control(char *s, va_list lst, t_flags *flag);

/* numeric_conversion.c */
void		numeric_conv_dispatcher(char c, va_list lst, char **res,		\
				t_flags *flags);

/* signed_conversion_handlers.c */
char		*handle_ll(long long ll_x, t_flags *flag);
char		*handle_l(long l_x, t_flags *flag);
char		*handle_h(int x, t_flags *flag);
char		*handle_hh(int x, t_flags *flag);
char		*handle_int(int x, t_flags *flag);

/* add_sign.c */
char		*add_sign(char *res);

/* unsigned_conversion_handlers.c */
char		*handle_ull(unsigned long long ll_x, t_flags *flag, int base);
char		*handle_ul(unsigned long l_x, t_flags *flag, int base);
char		*handle_uh(unsigned int x, t_flags *flag, int base);
char		*handle_uhh(unsigned int x, t_flags *flag, int base);
char		*handle_uint(unsigned int x, t_flags *flag, int base);

/* handle_double.c */
char		*convert_double(va_list lst, t_flags *flag);

/* double_helpers.c */
char		*neg_float_handler(char *res, t_flags *flag);
char		*rounding_algo(char *res, size_t prec);

/* double_helpers2.c */
void		set_x(va_list lst, t_flags *flag, long double *x);

/* flag_control.c */
char		*flag_control(char *res, t_flags flag);

/*	decimal_conv.c */
char		*convert_digit(va_list lst, t_flags *flag);
char		*convert_unsigned(va_list lst, t_flags *flag);

/* hash_flag.c */
char		*handle_hash(char *res, t_flags flag);

/* plus_flag.c */
char		*handle_plus(char *res, t_flags flag, int len);

/* ft_itoa_base.c */
char		*ft_itoa_base(const long long value, int base);
char		*itoa_reverse(char *str);

/* ft_itoa_base_unsigned.c */
char		*ft_itoa_base_unsigned(const unsigned long long value,			\
				int base);
/* ft_abs_long.c */
long long	ft_abs_long(long long i);

/* print_result.c */
void		print_result(char *s, t_flags flag, int *printf_res);

/* ft_printf_putstr.c */
void		ft_printf_putstr(char const *str, int *printf_res, t_flags flag);
void		ft_printf_putchar(char const *str, int i, int *printf_res);
#endif
