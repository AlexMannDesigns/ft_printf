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

/*
*	control function for handling the different types of output conversion
*	ft_is... functions might be needed for error handling
*	p & f conversions still needed
*/
char	*conversion_control(char *s, va_list lst, t_flags flag_data)
{
	char	*res;

	res = NULL;
	if (s[0] == 'd' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u' || s[0] == 'x' || s[0] == 'X')
		numeric_conv_dispatcher(s[0], va_arg(lst, int), &res);
	else if (s[0] == 's')
		res = ft_strdup(va_arg(lst, char *));
	else if (s[0] == 'c')
	{
		res = ft_strnew(2);
		res[0] = (char) va_arg(lst, int);
	}
	else
		res = ft_strdup("*** I'm not entirely sure this is the conversion you meant! ***"); //just here for testing
	return (res);
}