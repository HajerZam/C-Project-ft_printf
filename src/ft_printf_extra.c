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
#include "libft.h"

int	ft_putunsigned(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
		i += ft_putunsigned(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}

int ft_putptr(void *ptr)
{
    if (!ptr)
        return (ft_putstr("(nil)"));
    return (ft_putstr("0x") + ft_puthex((unsigned long)ptr, 0));
}

int	ft_count_digits_base(unsigned long n, int base)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(unsigned long n, char *base)
{
	int		len;
	char	*str;

	len = ft_count_digits_base(n, ft_strlen(base));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n > 0)
	{
		str[--len] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (str);
}
