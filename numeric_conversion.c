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

static char	*convert_hex_upper(int nb)
{
	return (ft_itoa_base(nb, 16));
}

static char	*convert_hex_lower(int nb)
{
	char	*res;
	int		i;

	res = ft_itoa_base(nb, 16);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = ft_tolower(res[i]);
		i++;
	}
	return (res);
}

static char	*convert_octal(int nb)
{
	return (ft_itoa_base(nb, 8));
}

static char	*convert_digit(int nb)
{
	return (ft_itoa_base(nb, 10));
}

void	numeric_conv_dispatcher(char c, int x, char **res, t_conv *conv)
{
	char	*(*p[4])(int nb);

	p[0] = convert_digit;
	p[1] = convert_octal;
	p[2] = convert_hex_lower;
	p[3] = convert_hex_upper;
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
}
