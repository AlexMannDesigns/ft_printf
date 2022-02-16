/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:31:56 by amann             #+#    #+#             */
/*   Updated: 2022/02/16 15:48:43 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 
*	if the precision is 0, simply chop off the decimal point and beyond
*	if we need a shorter number, we chop from the dp + precision
*	otherwise, pad out the number with 0s - remember to free memory!
*/

void	chop_chop(char **res_str, size_t prec)
{
	size_t	i;
	size_t	total;
	size_t	len;
	char	*new;

	len = ft_strlen(*res_str);
	i = 0;
	while ((*res_str)[i] != '.')
		i++;
	total = prec + i + 1;
	if (prec == 0)
		new = ft_strndup(*res_str, i);
	else if (total < len)
	{
		new = ft_strndup(*res_str, total);
	}
	else
	{
		new = ft_strnew(total);
		ft_strcpy(new, *res_str);
		ft_memset((void *)(new + len), '0', total - len);
	}
	free(*res_str);
	*res_str = new;
}

static char	*create_string(long int left_dp, long double right_dp)
{
	char		*int_str;
	char		*dec_str;
	char		*res_str;
	char		*temp_str;

	int_str = ft_itoa_base(left_dp, 10);
	res_str = ft_itoa_base((long int)right_dp, 10);
	dec_str = ft_strdup(res_str);
	free(res_str);
	temp_str = ft_strjoin(".", dec_str);
	res_str = ft_strjoin(int_str, temp_str);
	free(int_str);
	free(dec_str);
	free(temp_str);
	return (res_str);
}

char	*handle_double(long double x, t_flags *flag, t_width width)
{
	char		*res_str;
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
	res_str = create_string(left_dp, right_dp);
	if (width.prec > 17)
		res_str = rounding_algo(res_str, 17);
	else
		res_str = rounding_algo(res_str, width.prec);
	chop_chop(&res_str, width.prec);
	res_str = neg_float_handler(res_str, flag);
	return (res_str);
}
