/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/21 17:21:12 by amann            ###   ########.fr       */
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

void print_result(char *s, t_width width_data)
{
	char	*res;
	size_t	start;
	size_t	len;

	len = ft_strlen(s);
	start = 0;
	if (width_data.precision && width_data.precision > len)
		res = ft_strnew(width_data.precision);
	else if (width_data.width && width_data.width > len)
	{
		res = ft_strnew(width_data.width);
		ft_memset((void *)res, ' ', width_data.width - len);
		ft_strcpy((res + (width_data.width - len)), s);
	}
	else
	{
		res = ft_strnew(len);
		ft_strcpy(res, s);
	}
	if (width_data.precision > len && width_data.precision > width_data.width)
	{
		ft_memset((void *)res, '0', width_data.precision - len);
		ft_strcpy((res + (width_data.precision - len)), s);
	}
	else if (width_data.precision > len && width_data.width)
	{
		ft_memset((void *)res, ' ', width_data.width);
		ft_memset((void *)res + width_data.width - width_data.precision, '0', width_data.precision - len);
		ft_strcpy((res + (width_data.width - len)), s);
	}
	ft_putstr(res);
}

static void	ft_printf_helper(char *s, va_list lst, int *printf_i)
{
	int		i;
	t_flags	flag_data;
	t_width	width_data;
	char	*res;

	initialise_structs(&flag_data, &width_data);
	res = NULL;
	i = 0;
	while (!ft_isalpha(s[i]) || s[i] == 'h' || s[i] == 'l' || s[i] == 'L')
	{
		if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.')
			set_width_precision(s + i, &width_data, &i);
		set_flags_and_length(s + i, &flag_data, &i);
		i++;
	}
	res = conversion_control(s + i, lst, flag_data);
	print_result(res, width_data);
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
	return (0);
}
