/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:43:01 by amann             #+#    #+#             */
/*   Updated: 2022/01/25 14:47:45 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*hex_hash_helper(char *res, t_conv conv, size_t len)
{
	char	*new;
	char	*lower_hex;
	char	*upper_hex;

	lower_hex = "0x";
	upper_hex = "0X";
	new = ft_strnew(len + 2);
	if (conv.x)
		ft_strcpy(new, lower_hex);
	else
		ft_strcpy(new, upper_hex);
	ft_strcpy(new + 2, res);
	free(res);
	return (new);
}

/*	
*	Hexadecimal precision is handled in this part of the process, as the hash tag
*	results in 0 padding to happen between the conversion result an 0x prefix
*/

static char	*hex_precision(char *res, size_t prec)
{
	size_t	len;
	char	*new;

	if (!prec)
		return (res);
	len = ft_strlen(res);
	if (len < prec)
	{
		new = ft_strnew(prec);
		ft_memset(new, '0', prec - len);
		ft_strcpy(new + prec - len, res);
		free(res);
		return (new);
	}
	return (res);
}

char	*handle_hash(char *res, t_conv conv, t_width width, t_flags flag)
{
	char	*new;

	if (conv.o)
	{
		new = ft_strnew(ft_strlen(res) + 1);
		ft_memset(new, '0', 1);
		ft_strcpy(new + 1, res);
		free(res);
		return (new);
	}
	else if (conv.x || conv.big_x)
	{
		res = hex_precision(res, width.prec);
		if (flag.hash)
			return (hex_hash_helper(res, conv, ft_strlen(res)));
	}
	return (res);
}
