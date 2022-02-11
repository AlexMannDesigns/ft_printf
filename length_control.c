/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:44 by amann             #+#    #+#             */
/*   Updated: 2022/02/11 15:04:45 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_control(long int *x, va_list lst, t_flags *flags)
{
	if (flags->ll || flags->l || flags->conv.p || flags->conv.x \
		|| flags->conv.big_x || flags->conv.o)
		*x = va_arg(lst, long int);
	else
		*x = (long int) va_arg(lst, int);
	if (*x == 0)
		flags->nil = TRUE;
}

char	*length_dispatcher(char *(*p[4])(long), t_flags *flags, char c, \
			long int x)
{
	unsigned int	u;
	short			s;
	char			c_flag;

	if (c == 'u')
	{
		u = (unsigned int)x;
		return ((*p[0])((long int)u));
	}
	else if (c != 'p' && flags->h)
	{
		s = (short)x;
		return ((*p[0])((long int)s));
	}
	else if (c != 'p' && flags->hh)
	{
		c_flag = (char)x;
		return ((*p[0])((long int)c_flag));
	}
	else
		return (NULL);
}
