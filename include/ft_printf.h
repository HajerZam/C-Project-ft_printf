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

typedef struct s_fmt
{
	int		left;
	int		zero;
	int		width;
	int		prec;
	int		len_mod;
	char	spec;
}	t_fmt;

int		ft_printf(const char *fmt, ...);
int		parse_handle(const char **fmt, t_fmt *f, va_list args, int *i);
void	parse_specifier(const char **fmt, t_fmt *f);
int		handle_conversion(const char **fmt, va_list args);
int		check_conversion(char c);
int		check_flag(char c);
int		parse_flags(const char **fmt, int *left, int *zero);
int		parse_width_precision(const char **fmt, int *w, int *p);
int		parse_len(const char **fmt);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, int upper);

#endif