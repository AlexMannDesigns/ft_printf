/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:47:33 by amann             #+#    #+#             */
/*   Updated: 2022/02/16 15:51:57 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*neg_float_handler(char *res, t_flags *flag)
{
	char	*neg_res;

	if (flag->conv.neg)
	{
		neg_res = ft_strjoin("-", res);
		free(res);
		return (neg_res);
	}
	return (res);
}

static char	algo_helper_part2(char **res, size_t *len)
{
	size_t	i;

	i = 1;
	while ((*res)[*len + i] != '\0')
	{
		if ((*res)[*len + i] != '0')
			break ;
		i++;
	}
	return ((*res)[*len + i]);
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
		if ((*res)[*len - check] == '9')
		{
			(*res)[*len - check] = '0';
			(*len)--;
		}
		else
		{
			if ((*res)[*len] == '5' && !algo_helper_part2(res, len) \
				&& ((*res)[*len - check] + 1) % 2 != 0)
				break ;
			(*res)[*len - check] += 1;
			break ;
		}
	}
}

char	*rounding_algo(char *res, size_t prec)
{
	size_t	len;
	char	*new;

	len = 0;
	while (res[len] != '.')
		len++;
	len += prec + 1;
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
