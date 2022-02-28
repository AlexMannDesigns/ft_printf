/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:50 by amann             #+#    #+#             */
/*   Updated: 2022/02/28 15:44:13 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(char const *str, int i, int *printf_res, t_flags flag)
{
	int		count;
	char	*temp;

	if (flag.conv.c && flag.nil)
	{
		temp = ft_strchr(str, '0');
		*temp = '\0';
	}
	count = write(1, str, i);
	*printf_res += count;
}

void	ft_printf_putstr(char const *str, int *printf_res, t_flags flag)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
		i++;
	// ft_putnbr(i);
	// ft_putchar('\n');
	ft_printf_putchar(str, i, printf_res, flag);
}
