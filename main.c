/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:50:16 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/27 13:57:35 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	len1;
	int	len2;

	len1 = ft_printf("Hello, %s!\n", "world");
	len2 = printf("Hello, %s!\n", "world");
	printf("ft_printf length: %d\n", len1);
	printf("printf length: %d\n", len2);
	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');
	ft_printf("Decimal: %d\n", 42);
	printf("Decimal: %d\n", 42);
	ft_printf("String: %s\n", "Test string");
	printf("String: %s\n", "Test string");
	return (0);
}
