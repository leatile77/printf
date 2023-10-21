#include "main.h"
#include <stdio.h>

/**
 * _printf - Our printf Function, prints according to specified conversion
 * @format: conversion to useto print/ format specifier
 *
 * Return: number of chars printed / i
 */

int _printf(const char *format, ...)
{
int i, ch, num;
unsigned int unsnd, oct, hex;
char *str;
void *addr;

va_list arg;

va_start(arg, format);
i = 0;

while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == 'c')
{
ch = va_arg(arg, int);
i += print_char(ch);
}

else if (*format == 's')
{
str = va_arg(arg, char *);
i += print_string(str);
}

else if (*format == '%')
{
i += print_percent();
}

else if ((*format == 'i') || (*format == 'd'))
{
num = va_arg(arg, int);
i += print_int(num);
}

else if (*format == 'u')
{
unsnd = va_arg(arg, unsigned int);
i += print_unsigned(unsnd);
}

else if (*format == 'o')
{
oct = va_arg(arg, unsigned int);
i += print_octal(oct);
}

else if ((*format == 'x') || (*format == 'X'))
{
hex = va_arg(arg, unsigned int);
i += print_Hex(hex, format);
}

else if (*format == 'p')
{
addr = va_arg(arg, void *);
i += print_Address(addr);
}

}


else
{
_putchar(*format);
i++;
}

format++;
}

va_end(arg);
return (i);
}
