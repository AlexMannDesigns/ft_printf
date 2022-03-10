/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:00:09 by amann             #+#    #+#             */
/*   Updated: 2022/03/10 15:15:31 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	set_prec_helper(t_flags *data, va_list lst, int *ctrl_i)
{
	data->width.prec = va_arg(lst, int);
	*ctrl_i += 1;
}

static void	set_prec(const char *s, t_flags *data, int *ctrl_i, va_list lst)
{
	size_t	len;
	char	*pres_str;

	data->width.prec_set = TRUE;
	if (s[0] == '*')
		set_prec_helper(data, lst, ctrl_i);
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
			*ctrl_i += ((int) len - 1);
		else
			*ctrl_i += 1;
	}
	check_neg(data);
}

void	set_width_prec(const char *s, t_flags *data, int *ctrl_i, va_list lst)
{
	size_t	len;
	char	*width_str;

	if (s[0] == '.')
	{
		set_prec(s + 1, data, ctrl_i, lst);
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
		*ctrl_i += (int) len - 1;
	}
	check_neg(data);
}
