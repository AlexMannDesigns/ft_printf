/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by amann             #+#    #+#             */
/*   Updated: 2022/02/22 16:30:59 by amann            ###   ########.fr       */
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

static void	handle_zero_neg(char *res, size_t len)
{
	char	*temp;

	temp = ft_strnew(len);
	ft_strcpy(temp, res + 1);
	free(res);
	res = ft_strdup(temp);
	free(temp);
}

static char	*handle_zero(char *res, t_flags flag)
{
	char	*new;
	size_t	len;

	len = ft_strlen(res);
	if (flag.conv.neg && flag.conv.d)
		handle_zero_neg(res, --len);
	if (len > flag.width.width)
		return (res);
	new = ft_strnew(flag.width.width + 1);
	if (!new)
	{
		ft_memdel((void **)&res);
		return (NULL);
	}
	ft_memset(new, '0', flag.width.width - len);
	ft_strcpy(new + flag.width.width - len, res);
	free(res);
	if (flag.conv.big_x && flag.hash)
		hash_zero_hex(new, 'X');
	if (flag.conv.x && flag.hash)
		hash_zero_hex(new, 'x');
	if (flag.conv.neg && flag.conv.d)
		new[0] = '-';
	return (new);
}

char	*flag_control(char *res, t_flags flag)
{
	size_t	len;

	if (!res)
		return (NULL);
	if (((flag.hash && flag.conv.numeric) || ((flag.conv.x || flag.conv.big_x)
				&& flag.width.prec) || flag.conv.p) && res[0] != '0')
	{
		res = handle_hash(res, flag);
	}
	if (flag.zero && flag.conv.numeric && flag.width.width && !flag.width.prec
		&& !flag.left)
	{
		res = handle_zero(res, flag);
	}
	if ((flag.plus || flag.space) && flag.conv.d && !flag.conv.neg && res)
	{
		len = ft_strlen(res);
		res = handle_plus(res, flag, len);
	}
	return (res);
}
