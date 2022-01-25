/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:40 by amann             #+#    #+#             */
/*   Updated: 2022/01/25 14:47:59 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*	each time a new conversion starts, flag should all be set to FALSE */
void	initialise_structs(t_flags *flag, t_width *width, t_conv *conv)
{
	flag->h = FALSE;
	flag->hh = FALSE;
	flag->l = FALSE;
	flag->ll = FALSE;
	flag->big_l = FALSE;
	flag->hash = FALSE;
	flag->zero = FALSE;
	flag->left = FALSE;
	flag->plus = FALSE;
	flag->space = FALSE;
	flag->numeric = FALSE;
	width->prec = 0;
	width->width = 0;
	conv->numeric = FALSE;
	conv->percent = FALSE;
	conv->d = FALSE;
	conv->o = FALSE;
	conv->u = FALSE;
	conv->x = FALSE;
	conv->big_x = FALSE;
	conv->f = FALSE;
	conv->p = FALSE;
}

static void	set_flags(char *s, t_flags *flag)
{
	if (s[0] == 'L')
		flag->big_l = TRUE;
	else if (s[0] == '#')
		flag->hash = TRUE;
	else if (s[0] == '0')
		flag->zero = TRUE;
	else if (s[0] == '-')
		flag->left = TRUE;
	else if (s[0] == '+')
		flag->plus = TRUE;
	else if (s[0] == ' ')
		flag->space = TRUE;
}

void	set_flags_and_length(char *s, t_flags *flag, int *helper_i)
{
	set_flags(s, flag);
	if (s[0] == 'h' && s[1] == 'h')
	{
		flag->hh = TRUE;
		*helper_i += 1;
	}
	else if (s[0] == 'h')
		flag->h = TRUE;
	else if (s[0] == 'l' && s[1] == 'l')
	{
		flag->ll = TRUE;
		*helper_i += 1;
	}
	else if (s[0] == 'l')
		flag->l = TRUE;
}
