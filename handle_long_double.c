/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_long_double.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 13:02:39 by amann             #+#    #+#             */
/*   Updated: 2022/02/11 15:05:39 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*create_long_string(long int l_dp, long double r_dp, size_t prec)
{
	char		*int_str;
	char		*dec_str;
	char		*res_str;
	char		*temp_str;

	int_str = ft_itoa_base(l_dp, 10);
	res_str = ft_itoa_base((long int)r_dp, 10);
	dec_str = ft_strndup(res_str, prec);
	free(res_str);
	temp_str = ft_strjoin(".", dec_str);
	res_str = ft_strjoin(int_str, temp_str);
	free(int_str);
	free(dec_str);
	free(temp_str);
	return (res_str);
}

char	*handle_long_double(long double x, t_flags *flag, t_width width)
{
	char		*res_str;
	char		*neg_res;
	long int	left_dp;
	long double	right_dp;

	if (!width.prec_set)
		width.prec = 6;
	if (x < 0)
	{
		flag->conv.neg = TRUE;
		x *= -1;
	}
	left_dp = (long int) x;
	right_dp = ((x - (long double)left_dp) * 10e+17L);
	res_str = create_long_string(left_dp, right_dp, (width.prec + 1));
	res_str = rounding_algo(res_str);
	chop_chop(&res_str, width.prec);
	if (flag->conv.neg)
	{
		neg_res = ft_strjoin("-", res_str);
		free(res_str);
		return (neg_res);
	}	
	return (res_str);
}
