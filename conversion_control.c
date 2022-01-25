/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:16:46 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 10:16:46 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	control function for handling the different types of output conversion
*	ft_is... functions might be needed for error handling
*	p & f conversions still needed
*/
static void	set_conv_type(char c, t_conv *conv)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'p')
		conv->numeric = TRUE;
	if (c == 'd' || c == 'i')
		conv->d = TRUE;
	else if (c == 'o')
		conv->o = TRUE;
	else if (c == 'u')
		conv->u = TRUE;
	else if (c == 'x')
		conv->x = TRUE;
	else if (c == 'X')
		conv->big_x = TRUE;
	else if (c == 'f')
		conv->f = TRUE;
	else if (c == '%')
		conv->percent = TRUE;
}

static char	*handle_char(char c)
{
	char	*res;

	res = ft_strnew(2);
	res[0] = c;
	return (res);
}

char	*conversion_control(char *s, va_list lst, t_conv *conv, t_flags *flag)
{
	char	*res;

	res = NULL;
	if (s[0] == 'd' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u'
		|| s[0] == 'x' || s[0] == 'X')
	{
		flag->numeric = TRUE;
		numeric_conv_dispatcher(s[0], va_arg(lst, int), &res);
	}
	else if (s[0] == 'p')
	{
		flag->numeric = TRUE;
		numeric_conv_dispatcher(s[0], va_arg(lst, long int), &res);
	}
	else if (s[0] == 's')
		res = ft_strdup(va_arg(lst, char *));
	else if (s[0] == 'c')
		res = handle_char((char) va_arg(lst, int));
	else
		res = ft_strdup("*** This is not the conv you're looking for ***");
	set_conv_type(s[0], conv);
	return (res);
}
