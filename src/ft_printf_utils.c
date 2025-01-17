/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:22:27 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/16 12:22:27 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	check_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'n' || c == 'f')
		return (1); 
	if (c == 'e' || c == 'g' || c == 'a' || c == '%')
		return (1);
	return (0);
}
int	check_flag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int parse_flags(const char **format, int *left_justify, int *zero_padding)
{
	int flag_count = 0;

	while (**format == '-' || **format == '0')
	{
		if (**format == '-')
			*left_justify = 1;
		else if (**format == '0')
			*zero_padding = 1;
		(*format)++;
		flag_count++;
	}
	return (flag_count);
}
int parse_width_precision(const char **format, int *width, int *precision)
{
    *width = 0;
    *precision = -1;

    if (**format >= '0' && **format <= '9')
    {
        *width = ft_atoi(*format);
        while (**format >= '0' && **format <= '9')
            (*format)++;
    }
    if (**format == '.')
    {
        (*format)++;
        *precision = ft_atoi(*format);
        while (**format >= '0' && **format <= '9')
            (*format)++;
    }
    return (1);
}

int parse_length(const char **format)
{
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		(*format) += 2;
		return (1);
	}
	else if (**format == 'h')
	{
		(*format)++;
		return (2);
	}
	else if (**format == 'l' && *(*format + 1) == 'l')
	{
		(*format) += 2;
		return (3);
	}
	else if (**format == 'l')
	{
		(*format)++;
		return (4);
	}
	return (0);
}
