/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:26:46 by amann             #+#    #+#             */
/*   Updated: 2022/02/21 18:58:59 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*convert_digit_helper(long long int ll_x, t_flags *flag)
{
	int			x;
	long int	l_x;
	short		h_x;
	char		hh_x;

	if (flag->big_l)
		return (ft_itoa_base(ll_x, 10));
	else if (flag->l)
	{
		l_x = (long int) ll_x;
		return (ft_itoa_base((long long int)l_x, 10));
	}
	else if (flag->h)
	{
		h_x = (short) ll_x;
		return (ft_itoa_base((long long int)h_x, 10));
	}
	else if (flag->hh)
	{
		hh_x = (char) ll_x;
		return (ft_itoa_base((long long int)hh_x, 10));
	}
	x = (int) ll_x;
	return (ft_itoa_base((long long int)x, 10));
}

char	*convert_digit(va_list lst, t_flags *flag)
{
	long long int	ll_x;

	ll_x = va_arg(lst, long long int);
	if (ll_x < 0)
		flag->conv.neg = TRUE;
	return (convert_digit_helper(ll_x, flag));
}

static char	*convert_us_helper(unsigned long long ll_x, t_flags *flag, int base)
{
	unsigned int		x;
	unsigned long		l_x;
	unsigned short		h_x;
	unsigned char		hh_x;

	if (flag->big_l)
		return (ft_itoa_base_unsigned(ll_x, 10));
	else if (flag->l)
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
	if (flag->conv.u)
		return (convert_us_helper(ll_x, flag, 10));
	else if (flag->conv.o)
		return (convert_us_helper(ll_x, flag, 8));
	else if (flag->conv.big_x)
		return (convert_us_helper(ll_x, flag, 16));
	else
	{
		res = convert_us_helper(ll_x, flag, 16);
		i = 0;
		while (res[i] != '\0')
		{
			res[i] = ft_tolower(res[i]);
			i++;
		}
		return (res);
	}
}
