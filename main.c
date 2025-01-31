/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halzamma <halzamma@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 13:50:16 by halzamma          #+#    #+#             */
/*   Updated: 2025/01/28 14:26:41 by halzamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void test_case(const char *format, ...)
{
    va_list args1, args2;
    int ret1, ret2;

    va_start(args1, format);
    va_start(args2, format);

    printf("\nFormat: \"%s\"\n", format);

    ret1 = ft_printf("ft_printf: ");
    ret1 += ft_printf(format, args1);
    ft_printf("\n");
    
    ret2 = printf("printf   : ");
    ret2 += vprintf(format, args2);
    printf("\n");

    printf("Return values: ft_printf = %d, printf = %d\n", ret1, ret2);

    va_end(args1);
    va_end(args2);
}

int main(void)
{
    printf("=== Testing ft_printf vs printf ===\n");

    // Basic Tests
    test_case("Hello World");
    test_case("Simple test with one number: %d", 42);
    test_case("String: %s", "Hello, printf!");
    test_case("Char: %c", 'A');

    // Edge Cases
    test_case("Empty string: \"%s\"", "");
    test_case("Null string: \"%s\"", NULL);
    test_case("Minimum integer: %d", -2147483648);
    test_case("Maximum integer: %d", 2147483647);
    test_case("Unsigned zero: %u", 0);
    test_case("Hexadecimal zero: %x", 0);
    test_case("Null pointer: %p", NULL);

    // Width & Precision
    test_case("Width: %10d", 42);
    test_case("Precision: %.5d", 42);
    test_case("Width & Precision: %10.5d", 42);
    test_case("Left align: %-10d", 42);
    test_case("Zero padding: %010d", 42);

    // Flags
    test_case("Plus flag: %+d", 42);
    test_case("Space flag: % d", 42);
    test_case("Hash flag with x: %#x", 42);
    test_case("Hash flag with X: %#X", 42);

    // Multiple Arguments
    test_case("Multiple args: %d %s %c %x", 42, "Hello", 'A', 255);

    // Mixed Width, Precision, and Flags
    test_case("Complex: %+10.5d", 42);
    test_case("Left align with precision: %-10.5d", 42);
    test_case("Zero padding with width: %010s", "Hello");
    test_case("Width with negative number: %10d", -42);

    // Hexadecimal
    test_case("Hex lowercase: %x", 255);
    test_case("Hex uppercase: %X", 255);
    test_case("Large hex: %x", 0x7fffffff);

    // Edge Cases for All Specifiers
    test_case("Char edge: %c", '\0');
    test_case("Unsigned edge: %u", 4294967295u);
    test_case("Pointer large: %p", (void *)0x7fffffffffff);

    // Percent Literal
    test_case("Percent literal: %%");
    test_case("Multiple percent literals: %%%%");

    // Invalid Specifiers
    test_case("Invalid specifier: %y");
    test_case("Incomplete format: %");

    return 0;
}
