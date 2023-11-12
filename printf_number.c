#include "libftprintf.h"


int ft_putnbr(int n)
{
    int count;

    count = 0;
    if (n == -2147483648)
    {
        ft_putchar('-');
        ft_putchar('2');
        count = count + ft_putnbr(147483648) + 2;
    }
    else if (n < 0)
    {
        ft_putchar('-');
        count = count + ft_putnbr(-n) + 1; 
    }
    else if (n >= 10)
    {
        count = count + ft_putnbr(n / 10);
        count = count + ft_putnbr(n % 10);
    }
    else
    {
        ft_putchar(n + '0');
        count = count + 1;  
    }

    return (count);
}


int ft_putunsigned(unsigned int n)
{
    int count;

    count = 0;
    if (n >= 10)
        count = count + ft_putunsigned(n / 10);
    count = count + ft_putchar((n % 10) + '0');
    return (count);
}