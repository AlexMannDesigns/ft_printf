/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:00:46 by amann             #+#    #+#             */
/*   Updated: 2022/02/25 16:35:32 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*itoa_reverse(char *str)
{
	int		len;
	int		i;
	char	temp;

	len = ft_strlen(str) - 1;
	i = 0;
	while (i <= (len / 2))
	{
		temp = str[i];
		str[i] = str[len - i];
		str[len - i] = temp;
		i++;
	}
	return (str);
}

// static char	*itoa_helper_neg(long long nb, int base, char *res)
// {
// 	char	*arr;
// 	int		i;

// 	arr = "0123456789ABCDEF";
// 	i = 0;
// 	while (nb >= 1)
// 	{
// 		res[i] = arr[nb % base];
// 		nb = nb / base;
// 		i++;
// 	}
// 	res[i] = '-';
// 	//res[i + 1] = '\0';
// 	return (res);
// }

static char	*itoa_helper(long long nb, int base, char *res)
{
	char	*arr;
	int		i;

	arr = "0123456789ABCDEF";
	i = 0;
	while (nb > 0)
	{
		res[i] = arr[nb % base];
		nb = nb / base;
		i++;
	}
	//res[i] = '\0';
	return (res);
}

// static char	*negative_control(long long value, int base, char *res)
// {
// 	value = value * -1;
// 	if (base == 10)
// 		res = itoa_helper_neg(value, base, res);
// 	else
// 		res = itoa_helper(value, base, res);
// 	return (res);
// }

char	*ft_itoa_base(const long long value, int base)
{
	char			*res;
	int				i;
	long long		n;

	n = ft_abs_long(value);
	i = 0;
	ft_putnbr(n);
	ft_putchar('\n');
	while (n / base > 0)
	{	
		n = n / base;
		i++;
	}
	// ft_putnbr(i);
	// ft_putchar('\n');
	if (value == 0)
		return (ft_strdup("0"));
	// if (value < 0 && base == 10)
	// 	res = ft_strnew(i + 1);
	else
		res = ft_strnew(i);
	if (!res)
		return (NULL);
	// if (value < 0)
	// 	res = negative_control(value, base, res);
	else
		res = itoa_helper(value, base, res);
	return (itoa_reverse(res));
}
