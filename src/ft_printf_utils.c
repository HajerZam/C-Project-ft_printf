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
#include "libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		i += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

static int	ft_puthex_char(unsigned int n, int upper)
{
	if (n % 16 > 9)
	{
		if (upper)
			return (ft_putchar((n % 16) - 10 + 'A'));
		else
			return (ft_putchar((n % 16) - 10 + 'a'));
	}
	else
		return (ft_putchar((n % 16) + '0'));
}

int	ft_puthex(unsigned int n, int upper)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_puthex(n / 16, upper);
	i += ft_puthex_char(n, upper);
	return (i);
}
