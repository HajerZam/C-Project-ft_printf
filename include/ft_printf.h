/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:18:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/16 12:18:06 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *format, ...);
int handle_conversion(const char **format, va_list args);


int check_conversion(char c);
int check_flag(char c);
int parse_flags(const char **format, int *left_justify, int *zero_padding);
int parse_width_and_precision(const char **format, int *width, int *precision);
int parse_length(const char **format);


int ft_putchar(char c);
int ft_putstr(char *str, int fd);
int ft_putnbr(int n);

#endif