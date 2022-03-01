/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 16:18:53 by amann             #+#    #+#             */
/*   Updated: 2022/03/01 16:19:17 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_sign(char *res)
{
	char	*temp;
	size_t	len;

	len = ft_strlen(res) + 1;
	temp = ft_strnew(len);
	temp[0] = '-';
	ft_strcpy(temp + 1, res);
	free(res);
	return (temp);
}
