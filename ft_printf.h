/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/02/11 15:02:25 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/***** HEADER FILES *****/

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* printf needed for testing */

/***** MACROS *****/

# define TRUE 1
# define FALSE 0

/***** STRUCT PROTOTYPING *****/

typedef struct s_width
{
	size_t	prec;
	size_t	width;
	int		prec_set;
}			t_width;

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
	unsigned int	p;
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
	t_conv			conv;
}					t_flags;

/***** FUNCTION PROTOTYPING *****/

/* ft_printf.c */
int			ft_printf(char *s, ...);

/* set_flags.c */
void		set_flags_and_length(char *s, t_flags *flag, int *h_i, \
				t_width width);
void		initialise_structs(t_flags *flag, t_width *width);

/* width_precision.c */
void		set_width_precision(char *s, t_width *data, int *helper_i);

/* conversion_control.c */
char		*conversion_control(char *s, va_list lst, t_flags *flag, \
				t_width *width);
/* numeric_conversion.c */
void		numeric_conv_dispatcher(char c, va_list lst, char **res, \
				t_flags *flags);
/* handle_double.c */
char		*handle_double(double x, t_flags *flag, t_width width);
void		chop_chop(char **res_str, size_t prec);
char		*rounding_algo(char *res);

/* handle_long_double.c */
char		*handle_long_double(long double x, t_flags *flag, t_width width);

/* flag_control.c */
char		*flag_control(char *res, t_flags flag, t_width width);

/* length_control.c */
void		length_control(long int *x, va_list lst, t_flags *flags);
char		*length_dispatcher(char *(*p[4])(long), t_flags *flags, char c, \
				long int x);

/* hash_flag.c */
char		*handle_hash(char *res, t_conv conv, t_width width, t_flags flag);

/* plus_flag.c */
char		*handle_plus(char *res, t_flags flag, t_width width, size_t len);

/* ft_itoa_base.c */
char		*ft_itoa_base(const long int value, int base);

/* ft_abs_long.c */
long int	ft_abs_long(long int i);

/* print_result.c */
void		print_result(char *s, t_width w, t_flags flag);
#endif
