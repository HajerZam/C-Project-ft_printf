#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int my_count, original_count;
    char *null_str = NULL;

    my_count = ft_printf("My char: %c\n", 'A');
    original_count = printf("OG char: %c\n", 'A');
    printf("Char count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My string: %s\n", "Hello, world!");
    original_count = printf("OG string: %s\n", "Hello, world!");
    printf("String count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My NULL string: %s\n", null_str);
    original_count = printf("OG NULL string: %s\n", null_str ? null_str : "(null)");
    printf("NULL String count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    void *ptr = (void *)0x12345678;
    my_count = ft_printf("My pointer: %p\n", ptr);
    original_count = printf("OG pointer: %p\n", ptr);
    printf("Pointer count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My NULL pointer: %p\n", NULL);
    original_count = printf("OG NULL pointer: %p\n", NULL);
    printf("NULL Pointer count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My decimal: %d\n", -42);
    original_count = printf("OG decimal: %d\n", -42);
    printf("Decimal count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My unsigned: %u\n", (unsigned int)4294967295);
    original_count = printf("OG unsigned: %u\n", (unsigned int)4294967295);
    printf("Unsigned count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My hex lowercase: %x\n", 255);
    original_count = printf("OG hex lowercase: %x\n", 255);
    printf("Hex lowercase count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My hex uppercase: %X\n", 255);
    original_count = printf("OG hex uppercase: %X\n", 255);
    printf("Hex uppercase count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    my_count = ft_printf("My percent: %%\n");
    original_count = printf("OG percent: %%\n");
    printf("Percent count -> ft_printf: %d | printf: %d\n\n", my_count, original_count);

    return 0;
}
