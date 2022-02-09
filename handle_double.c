/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:31:56 by amann             #+#    #+#             */
/*   Updated: 2022/02/09 15:21:08 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*handle_double(va_list lst, t_flags *flag, size_t prec)
{
	char		*res;
	char		*final_res;
	double		test;
	long int	left_dp;
	double		right_dp;

	if (!prec)
		prec = 6;
	test = (va_arg(lst, double));
	if (test < 0)
	{
		flag->conv.numeric = TRUE;
		return (ft_strdup("0"));
	}
	left_dp = (long int) test;
	right_dp = ((test - (double)left_dp) * 10000000000);
	res = ft_itoa_base(left_dp, 10); // returns double rounded down as string
	final_res = ft_strndup(ft_itoa_base((long int)right_dp, 10), prec);
	final_res = ft_strjoin(".", final_res);	
	return (ft_strjoin(res, final_res));
}
