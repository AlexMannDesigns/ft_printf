/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/01/21 11:13:33 by amann            ###   ########.fr       */
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
	unsigned int	percent;
}					t_flags;

/***** FUNCTION PROTOTYPING *****/

/* ft_printf.c */
int		ft_printf(char *s, ...);

/* set_flags.c */
void	set_flags_and_length(char *s, t_flags *flag, int *helper_i);
void	initialise_flags(t_flags *flag);

/* conversion_control.c */
char	*conversion_control(char *s, va_list lst, t_flags flag_data);

/* numeric_conversion.c */
void	numeric_conv_dispatcher(char c, int x, char **res);

/* ft_itoa_base.c */
char	*ft_itoa_base(int value, int base);

#endif