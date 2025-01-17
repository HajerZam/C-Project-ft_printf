#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int len1 = ft_printf("Hello, %s!\n", "world");
    int len2 = printf("Hello, %s!\n", "world");
    printf("ft_printf length: %d\n", len1);
    printf("printf length: %d\n", len2);

    ft_printf("Character: %c\n", 'A');
    ft_printf("Decimal: %d\n", 42);
    ft_printf("String: %s\n", "Test string");

    return 0;
}
