/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:37:43 by amann             #+#    #+#             */
/*   Updated: 2022/03/02 14:52:46 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*width_helper(char *res, int len, t_width width, t_flags flag)
{
	char	*new;

	new = ft_strnew(width.width);
	if (!flag.left)
	{
		ft_memset((void *)new, ' ', (size_t)(width.width - len));
		ft_strcpy((new + (width.width - len)), res);
	}
	else
	{
		ft_strcpy(new, res);
		ft_memset((void *)(new + len), ' ', (size_t)(width.width - len));
	}
	return (new);
}

static void	precision_helper_part_2(char *res, char *new, t_width w, int len)
{
	if (w.prec > len && w.prec > w.width)
	{
		
		ft_memset((void *)new, '0', (size_t)(w.prec - len));
		ft_strcpy((new + (w.prec - len)), res);
	}
	else if (w.prec > len && w.width)
	{
		ft_memset((void *)new, ' ', (size_t) w.width);
		ft_memset((void *)(new + w.width - w.prec), '0', \
			(size_t)(w.prec - len));
		ft_strcpy((new + (w.width - len)), res);
	}
}

static void	precision_helper(char *res, char *new, t_width w, t_flags flag)
{
	int	len;

	len = (int) ft_strlen(res);
	if (flag.conv.neg && w.prec > (len - 1))
		w.prec += 1;
	precision_helper_part_2(res, new, w, len);
	if (w.prec > len && w.width && flag.left)
	{
		ft_memset((void *)new, '0', (size_t)(w.prec - len));
		ft_strcpy(new + w.prec - len, res);
		if (w.prec < w.width)
			ft_memset((void *)(new + w.prec), ' ', (size_t)(w.width - w.prec));
	}
	if (flag.conv.neg && w.prec > (len - 1))
	{
		res = ft_strchr(new, '0');
		res[0] = '-';
	}
}

static char	*set_memory(char *res, t_width w, t_flags flag)
{
	char	*new;
	int		len;

	len = (int) ft_strlen(res);
	if (flag.conv.neg && w.prec > (len - 1))
	{
		res[0] = '0';
		w.prec += 1;
	}
	if (w.prec && w.prec > len && w.width < w.prec && flag.conv.numeric)
		new = ft_strnew(w.prec);
	else if (w.width && w.width > len)
		new = width_helper(res, len, w, flag);
	else
		new = ft_strdup(res);
	return (new);
}

void	print_result(char *res, t_flags flag, int *printf_ret)
{
	char	*new;
	t_width	w;

	w = flag.width;
	if (!res)
		return ;
	new = set_memory(res, w, flag);
	if (!new)
		return ;
	if (flag.conv.numeric)
		precision_helper(res, new, w, flag);
	if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil && w.width)
		ft_memset(new, ' ', ft_strlen(new));
	else if (flag.conv.numeric && w.prec == 0 && w.prec_set && flag.nil
		&& !(flag.conv.o && flag.hash))
	{
		free(new);
		if (flag.conv.p)
			new = ft_strdup("0x");
		else
			new = ft_strdup("");
	}
	ft_printf_putstr(new, printf_ret, flag);
	free(new);
}
