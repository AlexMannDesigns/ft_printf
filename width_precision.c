/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:00:09 by amann             #+#    #+#             */
/*   Updated: 2022/02/24 15:19:49 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//if width == neg - this is taken as an '-' left-align flag and positive width
//if precision == neg, the precision value is ignored completely

static void	check_neg(t_flags *flag)
{
	if (flag->width.width < 0)
	{
		flag->left = TRUE;
		flag->width.width = ft_abs(flag->width.width);
	}
	if (flag->width.prec < 0)
	{
		flag->width.prec = 0;
		flag->width.prec_set = FALSE;
	}
}

static void	set_prec_helper(t_flags *data, va_list lst, int *helper_i)
{
	data->width.prec = va_arg(lst, int);
	*helper_i += 1;
}

static void	set_precision(char *s, t_flags *data, int *helper_i, va_list lst)
{
	size_t	len;
	char	*pres_str;

	data->width.prec_set = TRUE;
	if (s[0] == '*')
		set_prec_helper(data, lst, helper_i);
	else
	{
		len = 0;
		while (ft_isdigit(s[len]))
			len++;
		pres_str = ft_strndup(s, len);
		if (!pres_str)
		{
			data->width.prec = 0;
			return ;
		}
		data->width.prec = (size_t)ft_atoi(pres_str);
		free(pres_str);
		if (len > 1)
			*helper_i += (len - 1);
		else
			*helper_i += 1;
	}
	check_neg(data);
}

void	set_width_precision(char *s, t_flags *data, int *helper_i, va_list lst)
{
	size_t	len;
	char	*width_str;

	if (s[0] == '.')
	{
		set_precision(s + 1, data, helper_i, lst);
		return ;
	}
	if (data->width.prec_set)
		return ;
	if (s[0] == '*')
		data->width.width = va_arg(lst, int);
	else
	{
		len = 0;
		while (ft_isdigit(s[len]))
			len++;
		width_str = ft_strndup(s, len);
		data->width.width = ft_atoi(width_str);
		free(width_str);
		*helper_i += len - 1;
	}
	check_neg(data);
}
