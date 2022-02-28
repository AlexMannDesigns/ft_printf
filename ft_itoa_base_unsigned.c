/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:32:11 by amann             #+#    #+#             */
/*   Updated: 2022/02/28 15:34:49 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*itoa_helper_unsigned(unsigned long long nb, int base, char *res)
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
	res[i] = '\0';
	return (res);
}

char	*ft_itoa_base_unsigned(const unsigned long long value, int base)
{
	char				*res;
	int					i;
	unsigned long long	n;

	n = value;
	i = 0;
	// ft_putstr("itoa num: ");
	// ft_putnbr(n);
	// ft_putchar('\n');
	while (n / base > 0)
	{	
		n = n / base;
		i++;
	}
	// ft_putnbr(i);
	// ft_putchar('\n');
	if (value == 0)
		return (ft_strdup("0"));
	res = ft_strnew(i + 1);
	if (!res)
		return (NULL);
	res = itoa_helper_unsigned(value, base, res);
	return (itoa_reverse(res));
}
