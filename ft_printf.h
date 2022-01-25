/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/01/25 14:49:07 by amann            ###   ########.fr       */
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

typedef struct s_flags
{
	unsigned int	h;
	unsigned int	hh;
	unsigned int	l;
	unsigned int	ll;
	unsigned int	big_l;
	unsigned int	hash;
	unsigned int	zero;
	unsigned int	left;
	unsigned int	plus;
	unsigned int	space;
	unsigned int	numeric;
}					t_flags;

typedef struct s_width
{
	size_t	prec;
	size_t	width;
}			t_width;

typedef struct s_conv
{
	unsigned int	percent;
	unsigned int	numeric;
	unsigned int	d;
	unsigned int	o;
	unsigned int	u;
	unsigned int	x;
	unsigned int	big_x;
	unsigned int	f;
	unsigned int	p;
}					t_conv;

/***** FUNCTION PROTOTYPING *****/

/* ft_printf.c */
int		ft_printf(char *s, ...);

/* set_flags.c */
void	set_flags_and_length(char *s, t_flags *flag, int *helper_i);
void	initialise_structs(t_flags *flag, t_width *width, t_conv *conv);

/* width_precision.c */
void	set_width_precision(char *s, t_width *data, int *helper_i);

/* conversion_control.c */
char	*conversion_control(char *s, va_list lst, t_conv *conv, t_flags *flag);

/* numeric_conversion.c */
void	numeric_conv_dispatcher(char c, int x, char **res);

/* flag_control.c */
char	*flag_control(char *res, t_flags flag, t_conv conv, t_width width);

/* hash_fag.c */
char	*handle_hash(char *res, t_conv conv, t_width width, t_flags flag);

/* ft_itoa_base.c */
char	*ft_itoa_base(int value, int base);

/* print_result.c */
void	print_result(char *s, t_width w, t_flags flag, t_conv conv);
#endif
