/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parce.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 13:34:03 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/17 13:34:03 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	parse_specifier(const char **format, t_format *fmt)
{
	fmt->specifier = **format;
	(*format)++;
}

int	check_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	parse_flags(const char **format, t_format *fmt)
{
	while (check_flag(**format))
	{
		if (**format == '-')
			fmt->left_justify = 1;
		else if (**format == '0')
			fmt->zero_padding = 1;
		else if (**format == '#')
			fmt->length_modifier = 1;
		else if (**format == ' ')
			fmt->width = 1;
		else if (**format == '+')
			fmt->precision = 1;
		(*format)++;
	}
	return (1);
}

int	parse_width_precision(const char **format, t_format *fmt)
{
	fmt->width = 0;
	fmt->precision = -1;
	if (**format >= '0' && **format <= '9')
	{
		fmt->width = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	if (**format == '.')
	{
		(*format)++;
		fmt->precision = ft_atoi(*format);
		while (**format >= '0' && **format <= '9')
			(*format)++;
	}
	return (1);
}

int	parse_len(const char **format, t_format *fmt)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		fmt->length_modifier = 1;
		(*format) += 2;
	}
	else if (**format == 'h')
	{
		fmt->length_modifier = 2;
		(*format)++;
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		fmt->length_modifier = 3;
		(*format) += 2;
	}
	else if (**format == 'l')
	{
		fmt->length_modifier = 4;
		(*format)++;
	}
	else
		fmt->length_modifier = 0;
	return (1);
}
