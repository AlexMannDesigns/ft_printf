/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversion_handlers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:08 by amann             #+#    #+#             */
/*   Updated: 2022/02/28 15:06:03 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_sign(char *res)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(res) + 1;
	temp = ft_strnew(len);
	temp[0] = '-';
	ft_strcpy(temp + 1, res);
	free(res);
	return (temp);
}

char	*handle_ll(long long ll_x, t_flags *flag)
{
	char	*res;

	if (ll_x < 0)
		flag->conv.neg = TRUE;
	if (ll_x == 0)
		flag->nil = TRUE;
	res = ft_itoa_base(ft_abs_long(ll_x), BASE_TEN);
	if (flag->conv.neg)
	 	res = add_sign(res);
	return (res);
}

char	*handle_l(long l_x, t_flags *flag)
{
	char	*res;

	if (l_x < 0)
		flag->conv.neg = TRUE;
	if (l_x == 0)
		flag->nil = TRUE;
	res = ft_itoa_base(ft_abs_long(l_x), BASE_TEN);
	if (flag->conv.neg)
	{
		// ft_putstr("here    ");
	 	res = add_sign(res);
	}
	// ft_putchar('\n');
	// ft_putstr(res);
	// ft_putchar('\n');
	return (res);
}

char	*handle_h(int x, t_flags *flag)
{
	char	*res;
	short	h_x;

	h_x = (short) x;
	if (h_x < 0)
		flag->conv.neg = TRUE;
	if (h_x == 0)
		flag->nil = TRUE;
	res = ft_itoa_base((long long) ft_abs((int)h_x), BASE_TEN);
	if (flag->conv.neg)
	 	res = add_sign(res);
	return (res);
}

char	*handle_hh(int x, t_flags *flag)
{
	char	*res;
	char	hh_x;

	hh_x = (char) x;
	if (hh_x < 0)
		flag->conv.neg = TRUE;
	if (hh_x == 0)
		flag->nil = TRUE;
	res = ft_itoa_base((long long) ft_abs((int)hh_x), BASE_TEN);
	if (flag->conv.neg)
	 	res = add_sign(res);
	return (res);
}

char	*handle_int(int x, t_flags *flag)
{
	char	*res;

	if (x < 0)
	{
		// ft_putstr("here    ");
		flag->conv.neg = TRUE;
	}
	if (x == 0)
		flag->nil = TRUE;
	// ft_putchar('\n');
	// ft_putnbr(x);
	// ft_putchar('\n');
	res = ft_itoa_base((long long) ft_abs(x), BASE_TEN);
	
	if (flag->conv.neg)
	{
		res = add_sign(res);
	}
	// ft_putstr(res);
	// ft_putchar('\n');
	return (res);
}
