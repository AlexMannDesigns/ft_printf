/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:14:26 by amann             #+#    #+#             */
/*   Updated: 2022/02/28 15:27:20 by amann            ###   ########.fr       */
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

static char	*handle_zero_neg(char *res, int len)
{
	char	*temp;

	temp = ft_strnew(len);
	ft_strcpy(temp, res + 1);
	free(res);
	return (temp);
}

static char	*handle_zero(char *res, t_flags flag)
{
	char	*new;
	int		len;

	len = (int) ft_strlen(res);
	if (flag.conv.neg && flag.conv.d && (flag.width.width > len))
		res = handle_zero_neg(res, --len);
	// ft_putchar('\n');
	// ft_putstr(res);
	// ft_putchar('\n');
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
	// ft_putchar('\n');
	// ft_putstr(new);
	// ft_putchar('\n');
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
	int	len;

	if (!res)
		return (NULL);
	if (((flag.hash && flag.conv.numeric) && res[0] != '0') || flag.conv.p)
		res = handle_hash(res, flag);
	if (flag.zero && (flag.conv.numeric || flag.conv.percent)
		&& flag.width.width && !flag.width.prec && !flag.left)
	{
		res = handle_zero(res, flag);
	}
	if ((flag.plus || flag.space) && flag.conv.d && !flag.conv.neg && res)
	{
		len = (int) ft_strlen(res);
		res = handle_plus(res, flag, len);
	}
	return (res);
}
