/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/02/28 14:09:25 by amann            ###   ########.fr       */
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

static void	ft_printf_helper(char *s, va_list lst, int *printf_i, int *p_res)
{
	int		i;
	t_flags	flag_data;
	char	*res;

	initialise_structs(&flag_data);
	res = NULL;
	i = 0;
	while ((!ft_isalpha(s[i]) && s[i] != '%') || s[i] == 'h' || s[i] == 'l'
		|| s[i] == 'L')
	{
		if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.' || s[i] == '*')
			set_width_precision(s + i, &flag_data, &i, lst);
		set_flags_and_length(s + i, &flag_data, &i);
		i++;
	}
	res = conversion_control(s + i, lst, &flag_data);
	res = flag_control(res, flag_data);
	// ft_putstr(res);
	// ft_putchar('\n');
	print_result(res, flag_data, p_res);
	if (res)
		free(res);
	*printf_i += i + 1;
}

int	ft_printf(char *s, ...)
{
	va_list	lst;
	t_flags	temp;
	int		i;
	int		res;
	int		count;

	va_start(lst, s);
	initialise_structs(&temp);
	i = 0;
	res = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			ft_printf_putchar(s + count, i - count, &res, temp);
			ft_printf_helper(&s[i + 1], lst, &i, &res);
			count = i + 1;
		}
		i++;
	}
	ft_printf_putchar(s + count, i - count, &res, temp);
	va_end(lst);
	return (res);
}
