/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:12:50 by amann             #+#    #+#             */
/*   Updated: 2022/02/14 16:34:22 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_putchar(char c, int *printf_res)
{
	write(1, &c, 1);
	*printf_res += 1;
}

void	ft_printf_putstr(char const *str, int *printf_res)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_printf_putchar(str[i], printf_res);
		i++;
	}
}
