/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:55:46 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 11:55:46 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_hex_upper(long int nb)
{
	return (ft_itoa_base((long int)nb, 16));
}

static char	*convert_hex_lower(long int nb)
{
	char	*res;
	int		i;

	res = ft_itoa_base((long int)nb, 16);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	return (res);
}

static char	*convert_octal(long int nb)
{
	return (ft_itoa_base((long int)nb, 8));
}

static char	*convert_digit(long int nb)
{
	return (ft_itoa_base(ft_abs_long(nb), 10));
}

void	numeric_conv_dispatcher(char c, va_list lst, char **res, t_flags *flags)
{
	char		*(*p[4])(long int nb);
	char		*temp;
	long int	x;

	p[0] = convert_digit;
	p[1] = convert_octal;
	p[2] = convert_hex_lower;
	p[3] = convert_hex_upper;
	length_control(&x, lst, flags);
	if (x < 0 && (c != 'u' && c != 'x' && c != 'X' && c != 'o' && c != 'p'))
		flags->conv.neg = TRUE;
	if (c != 'p' && (flags->h || flags->hh || c == 'u'))
		*res = length_dispatcher(p, flags, c, x);
	if (c == 'd' || c == 'i')
		*res = (*p[0])(x);
	else if (c == 'o')
		*res = (*p[1])(x);
	else if (c == 'x' || c == 'p')
		*res = (*p[2])(x);
	else if (c == 'X')
		*res = (*p[3])(x);
	if (flags->conv.neg)
	{
		temp = *res;
		*res = ft_strjoin("-", *res);
		free(temp);
	}
}
