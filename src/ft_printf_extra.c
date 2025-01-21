/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:39:06 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/21 12:39:06 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putunsigned(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int	ft_putptr(void *ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthex((unsigned long)ptr, 0);
	return (i);
}
