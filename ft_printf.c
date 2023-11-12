#include "libftprintf.h"

int ft_hexadif(unsigned int n, char c)
{
    char *base;
    int count;

    count = 0;
    if (c == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    count = count + ft_puthexa(n, base);
    return (count);
}

int main_printer(const char c, va_list *rpg)
{
    int count;

    count = 0;
    if (c == 'c')
        count = count + ft_putchar(va_arg(*rpg, int)); //will pass current arg to char printer function which i'll create later.
    else if (c == 's')
        count = count + ft_putstr(va_arg(*rpg, char *));
    else if (c == 'd' || c == 'i')
        count = count + ft_putnbr(va_arg(*rpg, int));
    else if (c == 'p')
        count = count + ft_putptr(va_arg(*rpg, void *));
    else if (c == 'u')
        count = count + ft_putunsigned(va_arg(*rpg, unsigned int));
    else if (c == 'x' || c == 'X')
        count = count + ft_hexadif(va_arg(*rpg, unsigned int), c);
    else if (c == '%')
        count = count + ft_putchar('%');
    return (count);
}

int format_specifier(char c)
{
    if (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%')
        return (1); //will go on and return 1-0 depending on if i have it on list.
    else
        return (0);
}

int ft_printf(const char *str, ...)
{
    va_list va_rpg;
    va_start(va_rpg, str);
    int count;
    int i;

    i = 0;
    count = 0;
    while(str[i])
    {             
        if ((str[i] == '%') && (format_specifier(str[i + 1]) == 1))
        {
            count = count + main_printer(str[i + 1], &va_rpg);
            i = i + 2;
        }
        else
        {
            count = count + ft_putchar(str[i]);
            i++;
        }
    }
    va_end(va_rpg);
    return (count);
}

