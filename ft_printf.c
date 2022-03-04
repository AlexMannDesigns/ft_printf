/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:42:19 by amann             #+#    #+#             */
/*   Updated: 2022/03/04 16:39:11 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	control_loop(char *s, va_list lst, t_flags *flag_data)
{
	int	i;

	i = 0;
	while ((!ft_isalpha(s[i]) && s[i] != '%' && s[i] != '\0') || s[i] == 'h'
		|| s[i] == 'l' || s[i] == 'L')
	{
		if ((ft_isdigit(s[i]) && s[i] != '0') || s[i] == '.' || s[i] == '*')
			set_width_precision(s + i, flag_data, &i, lst);
		set_flags_and_length(s + i, flag_data, &i);
		i++;
	}
	return (i);
}

static void	ft_printf_control(char *s, va_list lst, int *printf_i, int *p_ret)
{
	int		i;
	t_flags	flag_data;
	char	*res;

	initialise_structs(&flag_data);
	res = NULL;
	i = control_loop(s, lst, &flag_data);
	res = conversion_control(s + i, lst, &flag_data, p_ret);
	if (!flag_data.conv.n)
	{
		res = flag_control(res, flag_data);
		print_result(res, flag_data, p_ret);
	}
	if (res)
		free(res);
	*printf_i += i + 1;
}

void	ft_printf_loop(char *s, va_list lst, int *ret)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' || s[i] == '{')
		{
			ft_printf_putchar(s + count, i - count, ret);
			if (s[i + 1] == '\0')
				break ;
			if (s[i] == '{')
				check_colour(s + i, &i, ret);
			else
				ft_printf_control((s + i + 1), lst, &i, ret);
			count = i + 1;
		}
		i++;
	}
	ft_printf_putchar(s + count, i - count, ret);
}

int	ft_printf(char *s, ...)
{
	va_list	lst;
	int		ret;

	va_start(lst, s);
	ret = 0;
	ft_printf_loop(s, lst, &ret);
	va_end(lst);
	return (ret);
}
