/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversion_handlers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:39:08 by amann             #+#    #+#             */
/*   Updated: 2022/02/25 16:33:18 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_sign(char *res)
{
	char	*new;

	new = ft_strnew(ft_strlen(res) + 1);
	new[0] = '-';
	ft_strcpy(new + 1, res);
	free(res);
	res = (char *) ft_strdup(new);
	free(new);
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
	 	add_sign(res);
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
	 	add_sign(res);
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
	 	add_sign(res);
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
	 	add_sign(res);
	return (res);
}

char	*handle_int(int x, t_flags *flag)
{
	char	*res;

	if (x < 0)
		flag->conv.neg = TRUE;
	if (x == 0)
		flag->nil = TRUE;
	res = ft_itoa_base((long long) ft_abs(x), BASE_TEN);
	if (flag->conv.neg)
	 	add_sign(res);
	return (res);
}
