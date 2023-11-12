#include "libftprintf.h"


int ft_puthexa(unsigned long n, char *base)
{
    int count;

    count = 0;
    if (n > 15)
    {
        count = count + ft_puthexa(n / 16, base);
        count = count + ft_puthexa(n % 16, base);
    }
    else
    {
        count = count + ft_putchar(base[n]);
    }
    return (count);
}

int ft_putptr(void *n)
{
    int count;
    unsigned long num;
    char *base;

    count = 0;
    base = "0123456789abcdef";
    num = (unsigned long)n;
    ft_putstr("0x");
    count = count + 2 + ft_puthexa(num, base);
    return (count);
}