/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by amann             #+#    #+#             */
/*   Updated: 2022/01/25 15:40:20 by amann            ###   ########.fr       */
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
*	figures are signed by default.
*	' ' leaves an empty space before positive numbers
*	% just prints a percentage sign.
*/
static char	*handle_zero(char *res, t_conv conv, size_t width, t_flags flag)
{
	char	*new;
	size_t	len;

	len = ft_strlen(res);
	if (len > width)
		return (res);
	if ((!conv.big_x && !flag.hash) || (!conv.x && !flag.hash))
	{
		new = ft_strnew(width + 1);
		ft_memset(new, '0', width - len);
		ft_strcpy(new + width - len, res);
		free(res);
		return (new);
	}
	//hexadecimal with # and 0 flag needs internal padding.
	return (res);	
}

char	*flag_control(char *res, t_flags flag, t_conv conv, t_width width)
{
	if ((flag.hash && conv.numeric) || ((conv.x || conv.big_x) && width.prec))
		return (handle_hash(res, conv, width, flag));
	if (flag.zero && conv.numeric && width.width && !width.prec && !flag.left)
		return (handle_zero(res, conv, width.width, flag));
	return (res);
}
