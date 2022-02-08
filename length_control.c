/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:09:44 by amann             #+#    #+#             */
/*   Updated: 2022/02/08 16:37:36 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	length_control(int *x, va_list lst, t_flags *flags)
{
	if (flags->ll || flags->l || flags->conv.p)
		*x = va_arg(lst, long int);
	// else if (flags->h && !flags->conv.f)
	// 	*x = va_arg(lst, short);
	// else if (flags->hh && !flags->conv.f)
	// 	*x = (long int) va_arg(lst, char);
	else
		*x = (long int) va_arg(lst, int);
}
