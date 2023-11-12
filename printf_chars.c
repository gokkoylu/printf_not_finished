#include "libftprintf.h"


int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putstr(const char *s)
{
    int count;

    count = 0;
    if (s)
    {
        while (*s)
        {
            count = count + ft_putchar(*s);
            s++;
        }
    }
    return (count);
}