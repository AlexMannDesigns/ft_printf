/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:25:40 by amann             #+#    #+#             */
/*   Updated: 2022/01/19 16:31:04 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*	each time a new conversion starts, flag should all be set to FALSE */
void	initialise_flags(t_flags *flag)
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
}

static void	handle_flags(char *s, t_flags *flag)
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

void	handle_flags_and_length(char *s, t_flags *flag, int *helper_i)
{
	handle_flags(s, flag);
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