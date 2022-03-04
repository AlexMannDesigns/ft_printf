/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <amann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:21:09 by amann             #+#    #+#             */
/*   Updated: 2022/03/04 17:01:39 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_colour_code(int i)
{
	char	*colour_code_arr[9];

	colour_code_arr[0] = BLACK;
	colour_code_arr[1] = RED;
	colour_code_arr[2] = GREEN;
	colour_code_arr[3] = YELLOW;
	colour_code_arr[4] = BLUE;
	colour_code_arr[5] = PURPLE;
	colour_code_arr[6] = CYAN;
	colour_code_arr[7] = WHITE;
	colour_code_arr[8] = RESET_COLOUR;
	ft_putstr(colour_code_arr[i]);
}

void	initialise_colour_arr(char **colour_str_arr)
{
	colour_str_arr[0] = ft_strdup("{black}");
	colour_str_arr[1] = ft_strdup("{red}");
	colour_str_arr[2] = ft_strdup("{green}");
	colour_str_arr[3] = ft_strdup("{yellow}");
	colour_str_arr[4] = ft_strdup("{blue}");
	colour_str_arr[5] = ft_strdup("{purple}");
	colour_str_arr[6] = ft_strdup("{cyan}");
	colour_str_arr[7] = ft_strdup("{white}");
	colour_str_arr[8] = ft_strdup("{reset}");
}

static size_t	set_len(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '}' && s[len] != '\0')
		len++;
	return (len);
}

void	check_colour(char *s, int *cursor, int *printf_ret)
{
	int		i;
	size_t	len;
	char	**colour_str_arr;

	colour_str_arr = (char **) ft_memalloc(sizeof(char *) * 9);
	initialise_colour_arr(colour_str_arr);
	len = set_len(s);
	if (s[len] == '\0')
		return ;
	i = 0;
	while (i < 9)
	{
		if (!ft_strncmp(s, colour_str_arr[i], len))
		{
			print_colour_code(i);
			break ;
		}
		i++;
	}
	if (i != 9)
		*cursor += (int) len;
	else
		ft_printf_putchar("{", 1, printf_ret);
	ft_freearray((void ***)&colour_str_arr, 9);
}
