/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:40 by amann             #+#    #+#             */
/*   Updated: 2022/02/22 16:50:26 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*	each time a new conversion starts, flag should all be set to FALSE */
static void	intialiser_helper(t_flags *flag)
{
	flag->width.prec = 0;
	flag->width.width = 0;
	flag->width.prec_set = FALSE;
	flag->conv.numeric = FALSE;
	flag->conv.percent = FALSE;
	flag->conv.d = FALSE;
	flag->conv.o = FALSE;
	flag->conv.u = FALSE;
	flag->conv.x = FALSE;
	flag->conv.big_x = FALSE;
	flag->conv.f = FALSE;
	flag->conv.p = FALSE;
	flag->conv.c = FALSE;
	flag->conv.s = FALSE;
	flag->conv.neg = FALSE;
}

void	initialise_structs(t_flags *flag)
{
	flag->h = FALSE;
	flag->hh = FALSE;
	flag->l = FALSE;
	flag->ll = FALSE;
	flag->big_l = FALSE;
	flag->hash = FALSE;
	flag->zero = FALSE;
	flag->nil = FALSE;
	flag->left = FALSE;
	flag->plus = FALSE;
	flag->space = FALSE;
	intialiser_helper(flag);
}

static void	set_flags(char *s, t_flags *flag)
{
	if (s[0] == 'L')
		flag->big_l = TRUE;
	else if (s[0] == '#')
		flag->hash = TRUE;
	else if (s[0] == '0' && !flag->width.width && !flag->width.prec)
		flag->zero = TRUE;
	else if (s[0] == '-')
		flag->left = TRUE;
	else if (s[0] == '+')
		flag->plus = TRUE;
	else if (s[0] == 32)
		flag->space = TRUE;
}

void	set_flags_and_length(char *s, t_flags *flag, int *h_i)
{
	set_flags(s, flag);
	if (s[0] == 'h' && s[1] == 'h')
	{
		flag->hh = TRUE;
		*h_i += 1;
	}
	else if (s[0] == 'h')
		flag->h = TRUE;
	else if (s[0] == 'l' && s[1] == 'l')
	{
		flag->ll = TRUE;
		*h_i += 1;
	}
	else if (s[0] == 'l')
		flag->l = TRUE;
}
