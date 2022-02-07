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

void	numeric_conv_dispatcher(char c, va_list lst, char **res, t_conv *conv, t_flags *flags)
{
	char			*(*p[4])(long int nb);
	long int	x; /* check flags to see if unsigned... will need to handle bigger nums */

	p[0] = convert_digit;
	p[1] = convert_octal;
	p[2] = convert_hex_lower;
	p[3] = convert_hex_upper;
	if (flags->ll || flags->l || !conv->p)
		x = va_arg(lst, long int);
	else
		x = va_arg(lst, int);
	// printf("%lld\n", x);
	if (x < 0)
		conv->neg = TRUE;
	if (c == 'd' || c == 'i')
		*res = (*p[0])(x);
	else if (c == 'o')
		*res = (*p[1])(x);
	else if (c == 'x' || c == 'p')
		*res = (*p[2])(x);
	else if (c == 'X')
		*res = (*p[3])(x);
	if (conv->neg)
		*res = ft_strjoin("-", *res);
}
