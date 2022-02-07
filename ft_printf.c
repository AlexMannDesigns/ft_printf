/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/02/02 15:49:03 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	list of args and address of i needed to determine conversion and how far
*	increment i process can effectively be split into two parts, one to handle
*	the flags, one for the conversion the conversion char will always be the
*	last character we are interested in, so we can iterate until hitting this
*	then increment the i in printf by the number of characters read.
*	We also need to handle width, precision and lenght before printing the
*	resulting string.
*/

static void	ft_printf_helper(char *s, va_list lst, int *printf_i)
{
	int		i;
	t_flags	flag_data;
	t_width	width_data;
	t_conv	conversion_type;
	char	*res;

	initialise_structs(&flag_data, &width_data, &conversion_type);
	res = NULL;
	i = 0;
	while ((!ft_isalpha(s[i]) && s[i] != '%') || s[i] == 'h' || s[i] == 'l' 
		|| s[i] == 'L')
	{
		if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
			set_width_precision(s + i, &width_data, &i);
		set_flags_and_length(s + i, &flag_data, &i, width_data);
		i++;
	}
	res = conversion_control(s + i, lst, &conversion_type, &flag_data);
	res = flag_control(res, flag_data, conversion_type, width_data);
	print_result(res, width_data, flag_data, conversion_type);
	if (res)
		free(res);
	*printf_i += i + 1;
}

/*add a percentage flag to the struct to save space*/

int	ft_printf(char *s, ...)
{
	va_list	lst;
	int		i;

	va_start(lst, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			ft_printf_helper(&s[i + 1], lst, &i);
		else
			ft_putchar(s[i]);
		i++;
	}
	va_end(lst);
	return (i);
}
