#include <stdio.h>
#include "main.h"

/**
 * print_buff - Function that prints buffer's content
 * @buffer: Content to print
 * @i_buff: index of buffer
 *
 * Return: void
 */

void print_buff(char buffer[], int *i_buff)
{
if (*i_buff > 0)
{
write(1,  buffer, *i_buff);
}

*i_buff = 0;
}

/**
 * _printf - Our printf function
 * @format: character specifying format
 *
 * Return: Number of printed chars
 */

int _printf(const char *format, ...)
{
int i, flags, width, precision, length, chars_num, h_print, i_buff;
char buffer[BUFF_SIZE];
va_list arg;

chars_num = 0;
h_print = 0;
i_buff = 0;

va_start(arg, format);

for (i = 0; (format != '\0') && (format[i] != '\0'); i++)
{
if (format[i] == '%')
{
print_buffer(buffer, &i_buff);
flags = get_flags(format, &i);
width = get_width(format, &i, arg);
precision = get_precision(format, &i, arg);
length = get_length(format, &i);
i++;

h_print = handle_print(format, &i, arg, buffer, flags, width, precision, length);

if (h_print == -1)
{
return (-1);
}

chars_num = chars_num + h_print;
}

else
{
buffer[i_buff++] = format[i];

if (i_buff == BUFF_SIZE)
{
print_buff(buffer, &i_buff);
chars_num++;
}
}
}

print_buff(buffer, &i_buff);

va_end(arg);
return (chars_num);
}
