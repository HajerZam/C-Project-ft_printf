/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:31:07 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/28 13:50:13 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

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

int	handle_conversion(t_fmt *fmt, va_list args)
{
	int	i;

	i = 0;
	if (fmt->spec == 'd' || fmt->spec == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (fmt->spec == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (fmt->spec == 'c')
		i += ft_putchar((char)va_arg(args, int));
	else if (fmt->spec == '%')
		i += ft_putchar('%');
	else if (fmt->spec == 'x')
		i += ft_puthex(va_arg(args, unsigned int), 0);
	else if (fmt->spec == 'X')
		i += ft_puthex(va_arg(args, unsigned int), 1);
	else if (fmt->spec == 'u')
		i += ft_putunsigned(va_arg(args, unsigned int));
	else if (fmt->spec == 'p')
		i += ft_putptr(va_arg(args, void *));
	return (i);
}

const char	*parse_handle(const char **fmt, t_fmt *f, va_list a, int *i)
{
	ft_memset(f, 0, sizeof(t_fmt));
	parse_flags(fmt, f);
	parse_width_precision(fmt, f);
	parse_len(fmt, f);
	parse_specifier(fmt, f);
	*i += handle_conversion(f, a);
	return (*fmt);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	t_fmt		fmt;

	i = 0;
	if (!format)
		return (0);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format = parse_handle(&format, &fmt, args, &i);
		}
		else
			i += ft_putchar(*format++);
	}
	va_end(args);
	return (i);
}
