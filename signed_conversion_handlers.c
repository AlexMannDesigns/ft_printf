/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversion_handlers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:08 by amann             #+#    #+#             */
/*   Updated: 2022/02/22 16:49:33 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_ll(long long ll_x, t_flags *flag)
{
	if (ll_x < 0)
		flag->conv.neg = TRUE;
	return (ft_itoa_base(ll_x, BASE_TEN));
}

char	*handle_l(long long ll_x, t_flags *flag)
{
	long	l_x;

	l_x = (long) ll_x;
	if (l_x < 0)
		flag->conv.neg = TRUE;
	return (ft_itoa_base((long long)l_x, BASE_TEN));
}

char	*handle_h(long long ll_x, t_flags *flag)
{
	short	h_x;

	h_x = (short) ll_x;
	if (h_x < 0)
		flag->conv.neg = TRUE;
	return (ft_itoa_base((long long)h_x, BASE_TEN));
}

char	*handle_hh(long long ll_x, t_flags *flag)
{
	char	hh_x;

	hh_x = (char) ll_x;
	if (hh_x < 0)
		flag->conv.neg = TRUE;
	return (ft_itoa_base((long long)hh_x, BASE_TEN));
}

char	*handle_int(long long ll_x, t_flags *flag)
{
	int	x;

	x = (int) ll_x;
	if (x < 0)
		flag->conv.neg = TRUE;
	return (ft_itoa_base((long long)x, BASE_TEN));
}
