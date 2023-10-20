#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(void);
int print_int(va_list arg);
int print_decimal(va_list arg);


#endif
