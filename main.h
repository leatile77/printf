#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(char c);
int print_string(char *str);
int print_percent(void);
int print_int(int n);
int print_unsigned(unsigned int unsnd);
int print_octal(unsigned int num);
/* int print_decimal(double num); */


#endif
