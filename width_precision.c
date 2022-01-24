/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 15:00:09 by amann             #+#    #+#             */
/*   Updated: 2022/01/24 14:43:09 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_precision(char *s, t_width *data, int *helper_i)
{
	size_t	len;
	char	*pres_str;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	pres_str = ft_strndup(s, len);
	data->prec = (size_t)ft_atoi(pres_str);
	free(pres_str);
	if (len > 1)
		*helper_i += (len - 1);
	else
		*helper_i += 1;
}

void	set_width_precision(char *s, t_width *data, int *helper_i)
{
	size_t	len;
	char	*width_str;

	if (s[0] == '.')
	{
		set_precision(s + 1, data, helper_i);
		return ;
	}
	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	width_str = ft_strndup(s, len);
	data->width = (size_t)ft_atoi(width_str);
	free(width_str);
	*helper_i += len - 1;
}
