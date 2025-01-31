/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:34:03 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/28 14:32:45 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <stdio.h>

void	parse_specifier(const char **format, t_fmt *fmt)
{
	fmt->spec = **format;
	if (check_conversion(fmt->spec))
		(*format)++;
	else
		fmt->spec = '\0';
}

int	check_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	parse_flags(const char **format, t_fmt *fmt)
{
	while (check_flag(**format))
	{
		if (**format == '-')
			fmt->left = 1;
		else if (**format == '0')
			fmt->zero = 1;
		else if (**format == '#')
			fmt->len_mod = 1;
		else if (**format == ' ')
			fmt->width = 1;
		else if (**format == '+')
			fmt->prec = 1;
		(*format)++;
	}
	return (1);
}

int	parse_width_precision(const char **format, t_fmt *fmt)
{
	fmt->width = 0;
	fmt->prec = -1;
	if (**format >= '0' && **format <= '9')
	{
		fmt->width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		fmt->prec = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	return (1);
}

int	parse_len(const char **format, t_fmt *fmt)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		fmt->len_mod = 1;
		(*format) += 2;
	}
	else if (**format == 'h')
	{
		fmt->len_mod = 2;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		fmt->len_mod = 3;
		(*format) += 2;
	}
	else if (**format == 'l')
	{
		fmt->len_mod = 4;
		(*format)++;
	}
	else
		fmt->len_mod = 0;
	return (1);
}
