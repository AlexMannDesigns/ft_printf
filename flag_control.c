/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by amann             #+#    #+#             */
/*   Updated: 2022/02/21 17:15:31 by amann            ###   ########.fr       */
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

	if (!res)
		return (NULL);
	len = ft_strlen(res);
	if (len > width)
		return (res);
	new = ft_strnew(width + 1);
	if (!new)
	{
		ft_memdel((void **)&res);
		return (NULL);
	}
	ft_memset(new, '0', width - len);
	ft_strcpy(new + width - len, res);
	free(res);
	if (conv.big_x && flag.hash)
		hash_zero_hex(new, 'X');
	if (conv.x && flag.hash)
		hash_zero_hex(new, 'x');
	return (new);
}

char	*flag_control(char *res, t_flags flag)
{
	size_t	len;
	t_conv	c;
	t_width	width;

	c = flag.conv;
	width = flag.width;
	if (!res)
		return (NULL);
	if ((flag.hash && c.numeric) || ((c.x || c.big_x) && width.prec) || c.p)
		res = handle_hash(res, c, width, flag);
	if (flag.zero && c.numeric && width.width && !width.prec && !flag.left)
		res = handle_zero(res, c, width.width, flag);
	if ((flag.plus || flag.space) && c.d && !c.neg && res)
	{
		len = ft_strlen(res);
		res = handle_plus(res, flag, width, len);
	}
	return (res);
}
