/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 08:50:35 by amann             #+#    #+#             */
/*   Updated: 2022/02/01 08:50:35 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	sign_selector(t_flags flag)
{
	if (flag.plus)
		return ('+');
	else
		return ((char)32);
}

static char	*plus_helper(int len, t_width width, char sign, char *res)
{
	char	*new;

	new = ft_strnew(len + (width.prec - len) + 1);
	if (!new)
		return (NULL);
	new[0] = sign;
	ft_strcpy(new + 1 + (width.prec - len), res);
	ft_memset(new + 1, '0', (width.prec - len));
	return (new);
}

char	*handle_plus(char *res, t_flags flag, t_width width, size_t len)
{
	char	*new;
	char	sign;

	sign = sign_selector(flag);
	if (width.prec > len)
		new = plus_helper(len, width, sign, res);
	else if (!flag.zero)
	{
		new = ft_strnew(len + 1);
		if (!new)
			return (NULL);
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