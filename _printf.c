#include "main.h"

/**
 *
 *
 *
 *
 *
 */

int _printf(const char *format, ...)
{
int i, ch, num, ;
char *str;
double dec;
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

else if (*format == 'i')
{
num = va_arg(arg, int);
i += print_int(num);
}

else if (*format == 'd')
{
dec = va_arg(arg, double);
i += print_decimal(dec);
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
