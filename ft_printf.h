/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:52:18 by amann             #+#    #+#             */
/*   Updated: 2022/01/19 14:58:59 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h> /* printf needed for testing */

typedef	struct	s_flags
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			L;
	int			hash;
	int			zero;
	int			left;
	int			plus;
	int			space;
}				t_flags;

int	ft_printf(char *s, ...);

#endif