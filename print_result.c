/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:43 by amann             #+#    #+#             */
/*   Updated: 2022/03/08 12:41:39 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_result_helper(char *new, t_flags flag)
{
	free(new);
	if (flag.conv.p)
		return (ft_strdup("0x"));
	else
	{
		return (ft_strdup(""));
	}
}

void	print_result(char *res, t_flags flag, int *printf_ret)
{
	char	*new;
	t_width	w;

	w = flag.width;
	if (!res)
		return ;
	new = set_memory(res, w, flag);
	if (!new)
		return ;
	if (flag.conv.numeric)
		precision_helper(res, new, w, flag);
	if (flag.conv.numeric && !w.prec && w.prec_set && flag.nil && w.width && !flag.plus)
		ft_memset(new, ' ', ft_strlen(new));
	else if (flag.conv.numeric && flag.nil && !(flag.conv.o && flag.hash) && !flag.plus
			&& !w.prec && w.prec_set && !(flag.conv.d && !w.width))
		new = print_result_helper(new, flag);
	if (!new)
		return ;
	ft_printf_putstr(new, printf_ret, flag);
	free(new);
}
