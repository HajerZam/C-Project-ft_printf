/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:31:07 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/11 14:31:07 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int handle_conversion(const char **format, va_list args)
{
    int count = 0;

    if (**format == 'd' || **format == 'i')
        count += ft_putnbr(va_arg(args, int));
    else if (**format == 's')
        ft_putstr(va_arg(args, char *), 1);
    else if (**format == 'c')
        count += ft_putchar((char)va_arg(args, int));
    else if (**format == '%')
        count += ft_putchar('%');
    return (count);
}

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;

    count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            count += handle_conversion(&format, args);
        }
        else
            count += ft_putchar(*format);
        format++;
    }
    va_end(args);
    return (count);
}
