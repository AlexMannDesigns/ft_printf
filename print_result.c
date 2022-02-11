/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:43 by amann             #+#    #+#             */
/*   Updated: 2022/02/11 11:41:32 by amann            ###   ########.fr       */
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
		ft_memset((void *)(res + len), ' ', width.width - len);
	}
	return (res);
}

static void	precision_helper_part_2(char *s, char *res, t_width w, size_t len)
{
	if (w.prec > len && w.prec > w.width)
	{
		ft_memset((void *)res, '0', w.prec - len);
		ft_strcpy((res + (w.prec - len)), s);
	}
	else if (w.prec > len && w.width)
	{
		ft_memset((void *)res, ' ', w.width);
		ft_memset((void *)(res + w.width - w.prec), '0', w.prec - len);
		ft_strcpy((res + (w.width - len)), s);
	}
}

static void	precision_helper(char *s, char *res, t_width w, t_flags flag)
{
	size_t	len;

	len = ft_strlen(s);
	if (flag.conv.neg && w.prec > (len - 1))
	{
		s[0] = '0';
		w.prec += 1;
	}
	precision_helper_part_2(s, res, w, len);
	if (w.prec > len && w.width && flag.left)
	{
		ft_memset((void *)res, '0', w.prec - len);
		ft_strcpy(res + w.prec - len, s);
		ft_memset((void *)(res + w.prec), ' ', w.width - w.prec);
	}
	if (flag.conv.neg && w.prec > (len - 1))
	{
		s = ft_strchr(res, '0');
		s[0] = '-';
	}
}

void	print_result(char *s, t_width w, t_flags flag)
{
	char	*res;
	size_t	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	if (w.prec && w.prec > len && w.width < w.prec && flag.conv.numeric
		&& !flag.conv.big_x && !flag.conv.x && !flag.conv.p)
		res = ft_strnew(w.prec);
	else if (w.width && w.width > len)
		res = width_helper(s, len, w, flag);
	else
		res = ft_strdup(s);
	if (!res)
		return ;
	if (!flag.conv.big_x && !flag.conv.x && !flag.conv.p && flag.conv.numeric)
		precision_helper(s, res, w, flag);
	if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil && w.width)
		ft_memset(res, ' ', ft_strlen(res));
	else if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil)
	{
		free(res);
		res = ft_strdup("");
	}
	ft_putstr(res);
}
