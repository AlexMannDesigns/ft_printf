/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:31:56 by amann             #+#    #+#             */
/*   Updated: 2022/02/11 13:03:35 by amann            ###   ########.fr       */
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

static void	algo_helper(char **res, size_t *len)
{
	size_t	check;

	while (*len)
	{
		check = 1;
		if ((*res)[*len] == '.')
			(*len)--;
		if ((*res)[*len - check] == '.')
			check = 2;
		if ((*res)[*len - check] < '9')
		{
			(*res)[*len - check] += 1;
			break ;
		}
		else
		{
			(*res)[*len - check] = '0';
			(*len)--;
		}
	}
}

/*	
*	len can be used to point to end of string
*	if the last digit is less than 5, we can return the number as is
*	otherwise, we need to go into our rounding algorithm
*/

char	*rounding_algo(char *res)
{
	size_t	len;
	char	*new;

	len = ft_strlen(res) - 1;
	if (res[len] < '5')
	{
		new = ft_strndup(res, len);
		free(res);
		return (new);
	}
	if (res[len] >= '5')
		algo_helper(&res, &len);
	if (len == 0 && (res)[len] == '0')
	{
		new = ft_strjoin("1", res);
		free(res);
		return (new);
	}
	return (res);
}

/*	
*	we can convert our double to a string by casting to an int
*	this rounds the number down, so we have the left side of the dp
*	to get the fractional part, we simply subtract the casted number
*	from the original double, then multiply that by whatever factor
*	of precision we would like. 15 decimal places feels about right
*/

static char	*create_string(long int left_dp, double right_dp, size_t prec)
{
	char		*int_str;
	char		*dec_str;
	char		*res_str;
	char		*temp_str;

	int_str = ft_itoa_base(left_dp, 10);
	res_str = ft_itoa_base((long int)right_dp, 10);
	dec_str = ft_strndup(res_str, prec);
	free(res_str);
	temp_str = ft_strjoin(".", dec_str);
	res_str = ft_strjoin(int_str, temp_str);
	free(int_str);
	free(dec_str);
	free(temp_str);
	return (res_str);
}

char	*handle_double(double x, t_flags *flag, t_width width)
{
	char		*res_str;
	char		*neg_res;
	long int	left_dp;
	double		right_dp;

	if (!width.prec_set)
		width.prec = 6;
	if (x < 0)
	{
		flag->conv.neg = TRUE;
		x *= -1;
	}
	left_dp = (long int) x;
	right_dp = ((x - (double)left_dp) * 10e+17L);
	res_str = create_string(left_dp, right_dp, (width.prec + 1));
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
