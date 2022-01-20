/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:00:46 by amann             #+#    #+#             */
/*   Updated: 2022/01/20 11:31:09 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_reverse(char *str)
{
	int	len;
	int	i;
	char	temp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= (len/2))
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return (str);
}

static char	*itoa_helper_neg(int nb, int base, char *res)
{
	char	*arr;
	int		i;

	arr = "0123456789ABCDEF";
	i = 0;
	while (nb >= 1)
	{
		res[i] = arr[nb % base];
		nb = nb / base;
		i++;
	}
	res[i] = '-';
	res[i + 1] = '\0';
	return (res);
}

static char	*itoa_helper(int nb, int base, char *res)
{
	char	*arr;
	int	i;

	arr = "0123456789ABCDEF";
	i = 0;
	while (nb > 0)
	{
		res[i] = arr[nb % base];
		nb = nb / base;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_base(int value, int base)
{
	char	*res;
	int 	i;
	int	n;

	n = value;
	i = 0;
	while ( n / base > 0)
	{	
		n = n / base;
		i++;
	}
	if (value < 0 && base == 10)
		res = (char *) malloc(sizeof(char) * (i + 1));
	else
		res = (char *) malloc(sizeof(char) * i);
	if (value < 0)
	{
		value = value * -1;
		if (base == 10)
			res = itoa_helper_neg(value, base, res);
		else
			res = itoa_helper(value, base, res);
	}
	else
		res = itoa_helper(value, base, res);
	return (itoa_reverse(res));
}