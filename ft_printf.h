/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/01/19 15:42:35 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* printf needed for testing */

# define TRUE 1
# define FALSE 0

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
}					t_flags;

int	ft_printf(char *s, ...);

#endif