/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 11:58:29 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
*	list of args and address of i needed to determine conversion and how far 
*	increment i process can effectively be split into two parts, one to handle
*	the flags, one for the conversion the conversion char will always be the 
*	last character we are interested in, so we can iterate until hitting this
*	then increment the i in printf by the number of characters read
*/

static void	ft_printf_helper(char *s, va_list lst, int *printf_i)
{
	int		i;
	t_flags	flag_data;
	char	*res;

	initialise_flags(&flag_data);
	res = NULL;
	i = 0;
	while (!ft_isalpha(s[i]) || s[i] == 'h' || s[i] == 'l' || s[i] == 'L')
	{
		if (s[i] == '%')
		{
			ft_putchar('%');
			break ;
		}
		else
			set_flags_and_length(s + i, &flag_data, &i);
		i++;
	}
	if (s[i] != '%')
		res = conversion_control(s + i, lst, flag_data);
	ft_putstr(res);
	if (res)
		free(res);
	*printf_i += i + 1;
}

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