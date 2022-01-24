/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:43 by amann             #+#    #+#             */
/*   Updated: 2022/01/24 15:12:41 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*width_helper(char *s, size_t len, t_width width, t_flags flag)
{
	char	*res;

	res = ft_strnew(width.width);
	if (!flag.left)
	{
		ft_memset((void *)res, ' ', width.width - len);
		ft_strcpy((res + (width.width - len)), s);
	}
	else
	{
		ft_strcpy(res, s);
		ft_memset((void *)res + len, ' ', width.width - len);
	}
	return (res);
}

static void	precision_helper(char *s, char *res, t_width w, t_flags flag)
{
	size_t	len;

	len = ft_strlen(s);
	if (w.prec > len && w.prec > w.width && flag.numeric)
	{
		ft_memset((void *)res, '0', w.prec - len);
		ft_strcpy((res + (w.prec - len)), s);
	}
	else if (w.prec > len && w.width && flag.numeric && flag.left)
	{
		ft_memset((void *)res, '0', w.prec - len);
		ft_strcpy(res + w.prec - len, s);
		ft_memset((void *)res + w.prec, ' ', w.width - w.prec);
	}
	else if (w.prec > len && w.width && flag.numeric)
	{
		ft_memset((void *)res, ' ', w.width);
		ft_memset((void *)res + w.width - w.prec, '0', w.prec - len);
		ft_strcpy((res + (w.width - len)), s);
	}
}

void		print_result(char *s, t_width w, t_flags flag)
{
	char	*res;
	size_t	start;
	size_t	len;

	len = ft_strlen(s);
	start = 0;
	if (w.prec && w.prec > len && w.width < w.prec && flag.numeric)
		res = ft_strnew(w.prec);
	else if (w.width && w.width > len)
		res = width_helper(s, len, w, flag);
	else
		res = ft_strdup(s);
	precision_helper(s, res, w, flag);
	ft_putstr(res);
}
