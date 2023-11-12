#ifndef LIBFTPRINF_H
#define LIBFT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int ft_putchar(char c);
int ft_putstr(const char *s);
int ft_puthexa(unsigned long n, char *base);
int ft_putptr(void *n);
int ft_putunsigned(unsigned int n);
int ft_putnbr(int n);
int ft_hexadif(unsigned int n, char c);
int main_printer(const char c, va_list *rpg);
int format_specifier(char c);
int ft_printf(const char *str, ...);


#endif