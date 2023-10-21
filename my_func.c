#include  "main.h"
#include <stdio.h>

/**
 * print_char - Function to Prints a character
 * @s: char to print
 *
 * Return: 1
 */

int print_char(char s)
{

_putchar(s);

return (1);
}

/**
 * print_string - Prints out a string of chars
 * @str: string to  print
 *
 * Return: Number of chars printed/ length
 */

int print_string(char *str)
{
int len;


while (*str != '\0')
{
_putchar(*str);
str++;
len++;
}
return (len);
}

/**
 * print_percent - Prints percent sign
 *
 * Return: 1
 */

int print_percent(void)
{
_putchar(37);
return (1);
}

/**
 * print_int - Prints an integer
 * @n: int argument to print
 *
 * Return: Number of chars printed / length
 */

int print_int(int n)
{
int i, rev;

i = 0;
rev = 0;

if (n == 0)
{
_putchar('0');
i++;
}

if (n < 0)
{
_putchar('-');
i++;
n = -n; /*after printing (-), we make n (+), prep to process*/
}

while (n > 0)
{
/*reverse the number, so we can print it from end to start*/
rev = rev * 10 + n % 10;
n /= 10; /*makes next digit the last each iteration*/
}

while (rev > 0)
{
_putchar(rev % 10 + '0'); /*Prints last digit of reversed num, appended*/
rev /= 10;
i++;
}

return (i);
}

/**
 * print_binary - Converts unsigned to binary and print
 * @num: number to convert and print
 *
 * Return: number of characters printed
 */

int print_binary(unsigned int num)
{
int i, j, n, bin[80];

n = 0;

if (num == 0)
{
_putchar('0');
return (1);
}

for (i = 0; num > 0; i++)
{
bin[i] = num % 2; /*conv to binary*/
num /= 2;
}

for (j = i - 1; j >= 0; j--)
{
_putchar('0' + bin[j]);
n++;
}

return (n);

}

/**
 * print_unsigned - Print unsignd int
 * @unsnd: unsignd to print
 *
 * Return: number of chars printed
 */

int print_unsigned(unsigned int unsnd)
{

int i, rev;

i = 0;
rev = 0;

if (unsnd == 0)
{
_putchar('0');
i++;
}

while (unsnd > 0)
{
/*reverse the number, so we can print it from end to start*/
rev = rev * 10 + unsnd % 10;
unsnd /= 10; /*makes next digit the last each iteration*/
}

while (rev > 0)
{
_putchar(rev % 10 + '0'); 
rev /= 10;
i++;
}

return (i);
}

/**
 * print_octal - Prints octal
 * @num: unsigned to print as octal
 *
 * Return: number of printed chars
 */

int print_octal(unsigned int num)
{
int i, j, n, oct[20];
n = 0;

if (num == 0)
{
_putchar('0');
return (1);
}

else
{
for (i = 0; num > 0; i++)
{
oct[i] = num % 8; /* convert to octal, store in reverse order */
num /= 8; /* remove converted */
}

for (j = i - 1; j >= 0; j--)
{
_putchar('0' + oct[j]); /*reverse reversed oct, print in forward order*/
n++;
}
}

return (n);
}

/**
 * print_Hex - A function that prints a hexadecimal
 * @num: unsigned int to convert and print as hexadecimal
 *
 * Return: number of characters printed
 */

int print_Hex(unsigned int num, const char *format)
{
int i, j, n, hexed;
char hexStore[20];

n = 0;
hexed = 0;

if (num == 0)
{
_putchar('0');
return (1);
}

for (i = 0; num > 0; i++)
{
hexed = num % 16; /* convert to hex */

if (hexed > 10)
{
if (*format == 'x')
{
hexStore[i] = hexed + 'a' - 10; /* conv values > 10 to a-f */
}
else if (*format == 'X')
{
hexStore[i] = hexed + 'A' - 10; /* conv val > 10 to A-F */
}
}

else
{
hexStore[i] = hexed + '0';
}

num /= 16; /* remove converted hex, prep for next*/
}

for (j = i - 1; j >= 0; j--)
{
_putchar(hexStore[j]);
n++;
}

return (n);
}


/**
 * print_Address - Function that prints an address/ pointer value
 * @ptr: void pointer to print
 *
 * Return: number of chars printed
 */

int print_Address(void *ptr)
{
char hexStore[15];
int i, j, n, hexed;
unsigned long int addr;

addr = (unsigned long int)ptr;
n = 0;
hexed = 0;

_putchar('0');
_putchar('x');
n += 2;

for (i = 0; addr > 0; i++)
{
hexed = addr % 16; /*conv to hex*/
if (hexed < 10)
{
hexStore[i] = hexed + '0';
}

else
{
hexStore[i] = hexed + 'a' - 10;
}
addr /= 16; /* rid of past conv, get new one */
}

for (j = i - 1; j >= 0; j--)
{
_putchar(hexStore[j]);
n++;
}

return (n);
}
