/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:43 by amann             #+#    #+#             */
/*   Updated: 2022/02/24 15:22:26 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*width_helper(char *s, int len, t_width width, t_flags flag)
{
	char	*res;

	res = ft_strnew(width.width);
	if (!flag.left)
	{
		ft_memset((void *)res, ' ', (size_t)(width.width - len));
		ft_strcpy((res + (width.width - len)), s);
	}
	else
	{
		ft_strcpy(res, s);
		ft_memset((void *)(res + len), ' ', (size_t)(width.width - len));
	}
	return (res);
}

static void	precision_helper_part_2(char *s, char *res, t_width w, int len)
{
	if (w.prec > len && w.prec > w.width)
	{
		ft_memset((void *)res, '0', (size_t)(w.prec - len));
		ft_strcpy((res + (w.prec - len)), s);
	}
	else if (w.prec > len && w.width)
	{
		ft_memset((void *)res, ' ', (size_t) w.width);
		ft_memset((void *)(res + w.width - w.prec), '0', \
			(size_t)(w.prec - len));
		ft_strcpy((res + (w.width - len)), s);
	}
}

static void	precision_helper(char *s, char *res, t_width w, t_flags flag)
{
	int	len;

	len = (int) ft_strlen(s);
	if (flag.conv.neg && w.prec > (len - 1))
		w.prec += 1;
	precision_helper_part_2(s, res, w, len);
	if (w.prec > len && w.width && flag.left)
	{
		ft_memset((void *)res, '0', (size_t)(w.prec - len));
		ft_strcpy(res + w.prec - len, s);
		if (w.prec < w.width)
			ft_memset((void *)(res + w.prec), ' ', (size_t)(w.width - w.prec));
	}
	if (flag.conv.neg && w.prec > (len - 1))
	{
		s = ft_strchr(res, '0');
		s[0] = '-';
	}
}

static char	*set_memory(char *s, t_width w, t_flags flag)
{
	char	*res;
	int		len;

	len = (int) ft_strlen(s);
	if (flag.conv.neg && w.prec > (len - 1))
	{
		s[0] = '0';
		w.prec += 1;
	}
	if (w.prec && w.prec > len && w.width < w.prec && flag.conv.numeric
		&& !flag.conv.big_x && !flag.conv.x && !flag.conv.p)
		res = ft_strnew(w.prec);
	else if (w.width && w.width > len)
		res = width_helper(s, len, w, flag);
	else
		res = ft_strdup(s);
	return (res);
}

void	print_result(char *s, t_flags flag, int *printf_res)
{
	char	*res;
	t_width	w;

	w = flag.width;
	if (!s)
		return ;
	res = set_memory(s, w, flag);
	if (!res)
		return ;
	if (flag.conv.numeric)
		precision_helper(s, res, w, flag);
	if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil && w.width)
		ft_memset(res, ' ', ft_strlen(res));
	else if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil
		&& !(flag.conv.o && flag.hash))
	{
		free(res);
		res = ft_strdup("");
	}
	ft_printf_putstr(res, printf_res, flag);
}
