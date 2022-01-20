/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:16:46 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 10:16:46 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* control function for handling the different types of output conversion */
char	*conversion_control(char *s, va_list lst, t_flags flag_data)
{
	int		x;
	char	*res;

	res = NULL;
	x = va_arg(lst, int);
	if (s[0] == 'd' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'x' || s[0] == 'X')
		numeric_conv_dispatcher(s[0], x, &res);
	return (res);
}