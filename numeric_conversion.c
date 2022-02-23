/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:46 by amann             #+#    #+#             */
/*   Updated: 2022/02/23 13:01:20 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*convert_digit(va_list lst, t_flags *flag)
{
	long long	ll_x;

	ll_x = va_arg(lst, long long);
	if (ll_x == 0)
		flag->nil = TRUE;
	if (flag->ll)
		return (handle_ll(ll_x, flag));
	else if (flag->l)
		return (handle_l(ll_x, flag));
	else if (flag->h)
		return (handle_h(ll_x, flag));
	else if (flag->hh)
		return (handle_hh(ll_x, flag));
	else
		return (handle_int(ll_x, flag));
}

static char	*convert_us_helper(unsigned long long ll_x, t_flags *flag, int base)
{
	unsigned int		x;
	unsigned long		l_x;
	unsigned short		h_x;
	unsigned char		hh_x;

	if (flag->ll)
		return (ft_itoa_base_unsigned(ll_x, base));
	else if (flag->l || flag->conv.p)
	{
		l_x = (unsigned long) ll_x;
		return (ft_itoa_base_unsigned((unsigned long long)l_x, base));
	}
	else if (flag->h)
	{
		h_x = (unsigned short) ll_x;
		return (ft_itoa_base_unsigned((unsigned long long)h_x, base));
	}
	else if (flag->hh)
	{
		hh_x = (unsigned char) ll_x;
		return (ft_itoa_base_unsigned((unsigned long long)hh_x, base));
	}
	x = (unsigned int) ll_x;
	return (ft_itoa_base_unsigned((unsigned long long)x, base));
}

char	*convert_unsigned(va_list lst, t_flags *flag)
{
	unsigned long long	ll_x;
	size_t				i;
	char				*res;

	ll_x = va_arg(lst, unsigned long long);
	if (ll_x == 0)
		flag->nil = TRUE;
	if (flag->conv.u)
		return (convert_us_helper(ll_x, flag, BASE_TEN));
	else if (flag->conv.o)
		return (convert_us_helper(ll_x, flag, BASE_EIGHT));
	else if (flag->conv.big_x)
		return (convert_us_helper(ll_x, flag, BASE_SIXTEEN));
	else
	{
		res = convert_us_helper(ll_x, flag, BASE_SIXTEEN);
		i = 0;
		while (res[i] != '\0')
		{
			res[i] = ft_tolower(res[i]);
			i++;
		}
		return (res);
	}
}
