/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/24 13:48:49 by amann            ###   ########.fr       */
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

static char	*width_helper(char *s, size_t len, t_width width, t_flags flag)
{
	char	*res;

	res = ft_strnew(width.width);
	if (!flag.left)
	{
		ft_memset((void *)res, ' ', width.width - len);
		ft_strcpy((res + (width.width - len)), s);	
	}
	else
	{
		ft_strcpy(res, s);
		ft_memset((void *)res + len, ' ', width.width - len);
	}
	return (res);
}

static void	precision_helper(char *s, char *res, t_width w, t_flags flag)
{
	size_t len;

	len = ft_strlen(s);
	if (w.precision > len && w.precision > w.width && flag.numeric)
	{
		ft_memset((void *)res, '0', w.precision - len);
		ft_strcpy((res + (w.precision - len)), s);
	}
	else if (w.precision > len && w.width && flag.numeric && flag.left)
	{
		ft_memset((void *)res, '0', w.precision - len);
		ft_strcpy(res + w.precision - len, s);
		ft_memset((void *)res + w.precision, ' ', w.width - w.precision);
	}
	else if (w.precision > len && w.width && flag.numeric)
	{
		ft_memset((void *)res, ' ', w.width);
		ft_memset((void *)res + w.width - w.precision, '0', w.precision - len);
		ft_strcpy((res + (w.width - len)), s);
	}
}

void print_result(char *s, t_width width, t_flags flag)
{
	char	*res;
	size_t	start;
	size_t	len;

	len = ft_strlen(s);
	start = 0;
	if (width.precision && width.precision > len && flag.numeric)
		res = ft_strnew(width.precision);
	else if (width.width && width.width > len)
		res = width_helper(s, len, width, flag);
	else
		res = ft_strdup(s);
	precision_helper(s, res, width, flag);
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
	res = conversion_control(s + i, lst, &flag_data);
	print_result(res, width_data, flag_data);
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
