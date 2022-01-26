/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by amann             #+#    #+#             */
/*   Updated: 2022/01/26 14:44:08 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	handling of flags is somewhat conversion-dependant.
*	# results in prefixing octal and hex conversions with 0 and 0x respectively
*	f conversions will always display a decimal point with this flag
*	0 pads all numeric conversions with '0' characters, but ignored if - flag
*	or precision value is given. Only works with width value
*	- left aligns output within field boundaries NB no effect without width
*	+ results in a sign ('+' or '-') always being printed before figure, negative
*	figures are signed by default. Only decimal conversions. Works with 0 flag
*	' ' leaves an empty space before positive numbers
*	% just prints a percentage sign.
*/
static void	hash_zero_hex(char *new, char x)
{
	int	i;

	i = 0;
	while (new[i] != '\0')
	{
		if (new[i] == x)
		{
			new[i] = '0';
			break ;
		}
		i++;
	}
	new[1] = x;
}

static char	*handle_zero(char *res, t_conv conv, size_t width, t_flags flag)
{
	char	*new;
	size_t	len;

	len = ft_strlen(res);
	if (len > width)
		return (res);
	new = ft_strnew(width + 1);
	ft_memset(new, '0', width - len);
	ft_strcpy(new + width - len, res);
	free(res);
	if (conv.big_x && flag.hash)
		hash_zero_hex(new, 'X');
	if (conv.x && flag.hash)
		hash_zero_hex(new, 'x');
	return (new);
}

static char	sign_selector(t_flags flag)
{
	if (flag.plus)
		return ('+');
	else
		return ((char)32);
}

static char	*handle_plus(char *res, t_flags flag, t_width width, size_t len)
{
	char	*new;
	char	sign;

	sign = sign_selector(flag);
	if (width.prec > len)
	{
		new = ft_strnew(len + (width.prec - len) + 1);
		new[0] = sign;
		ft_strcpy(new + 1 + (width.prec - len), res);
		ft_memset(new + 1, '0', (width.prec - len));
	}
	else if (!flag.zero)
	{
		new = ft_strnew(len + 1);
		new[0] = sign;
		ft_strcpy(new + 1, res);
	}
	else
	{
		res[0] = sign;
		return (res);
	}
	free(res);
	return (new);
}

char	*flag_control(char *res, t_flags flag, t_conv conv, t_width width)
{
	size_t	len;

	if ((flag.hash && conv.numeric) || ((conv.x || conv.big_x) && width.prec))
		res = handle_hash(res, conv, width, flag);
	if (flag.zero && conv.numeric && width.width && !width.prec && !flag.left)
		res = handle_zero(res, conv, width.width, flag);
	if ((flag.plus || flag.space) && conv.d && !conv.neg)
	{
		len = ft_strlen(res);
		res = handle_plus(res, flag, width, len);
	}
	return (res);
}
