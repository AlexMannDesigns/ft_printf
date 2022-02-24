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
	else if (c == 'c')
		conv->c = TRUE;
	else if (c == 's')
		conv->s = TRUE;
	else if (c == 'p')
		conv->p = TRUE;
}

static char	*handle_percent(void)
{
	char	*res;

	res = ft_strnew(1);
	if (!res)
		return (NULL);
	res[0] = '%';
	return (res);
}

static char	*convert_char(va_list lst, t_flags *flag)
{
	char			*res;
	unsigned char	c;

	c = (unsigned char) va_arg(lst, int);
	res = ft_strnew(1);
	if (!res)
		return (NULL);
	if (!c)
	{
		flag->nil = TRUE;
		res[0] = '0';
		return (res);
	}
	res[0] = c;
	return (res);
}

static char	*convert_string(va_list lst, t_flags *flag)
{
	char	*res;
	char	*temp;

	res = ft_strdup(va_arg(lst, char *));
	if (!res)
		res = ft_strdup("(null)");
	if (flag->width.prec_set)
	{
		temp = ft_strnew(flag->width.prec);
		if (!temp)
			return (NULL);
		ft_strncpy(temp, res, flag->width.prec);
		free(res);
		res = temp;
	}
	return (res);
}

char	*conversion_control(char *s, va_list lst, t_flags *flag)
{
	char	*(*p[5])(va_list lst, t_flags *flag);
	char	*res;

	p[0] = convert_digit;
	p[1] = convert_unsigned;
	p[2] = convert_char;
	p[3] = convert_string;
	p[4] = convert_double;
	res = NULL;
	set_conv_type(s[0], &(flag->conv));
	if (flag->conv.d)
		res = (*p[0])(lst, flag);
	else if (flag->conv.u || flag->conv.o || flag->conv.x || flag->conv.big_x
		|| flag->conv.p)
		res = (*p[1])(lst, flag);
	else if (flag->conv.c)
		res = (*p[2])(lst, flag);
	else if (flag->conv.s)
		res = (*p[3])(lst, flag);
	else if (flag->conv.f)
		res = (*p[4])(lst, flag);
	else if (flag->conv.percent)
		res = handle_percent();
	return (res);
}
