/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:31:56 by amann             #+#    #+#             */
/*   Updated: 2022/02/09 16:29:26 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* there are probably some mem leaks in this implementation */
/* helper functions needed to handle rounding and precision */
/* further function needed to correctly handle negative int */

char	*handle_double(double x, t_flags *flag, t_width width)
{
	char		*int_str;
	char		*dec_str;
	long int	left_dp;
	double		right_dp;

	if (!width.prec_set)
		width.prec = 6;
	if (x < 0)
	{
		flag->conv.numeric = TRUE;
		return (ft_strdup("0"));
	}
	left_dp = (long int) x;
	right_dp = ((x - (double)left_dp) * 10000000000000000L);
	int_str = ft_itoa_base(left_dp, 10); // returns double rounded down as string
	dec_str = ft_strndup(ft_itoa_base((long int)right_dp, 10), width.prec);
	dec_str = ft_strjoin(".", dec_str);	
	return (ft_strjoin(int_str, dec_str));
}
