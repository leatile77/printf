#include  "main.h"

/**
 * print_char - Function to Prints a character
 * @value: argument to print
 *
 * Return: 1
 */

int print_char(va_list arg)
{
char s;
s = va_arg(value, int);
_putchar(s);

return (1);
}

/**
 * print_string - Prints out a string of chars
 * @value: string arg to  print
 *
 * Return: Number of chars printed/ length
 */

int print_string(va_list arg)
{
char *s;
int len;

s = va_arg(arg, char *);

while (*s != '\0')
{
_putchar(*s);
s++;
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
 * @arg: int argument to print
 *
 * Return: Number of chars printed / length
 */

int print_int(va_list arg)
{
int i, n, rev;

n = va_arg(arg, int);
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
 * print_decimal - Function that prints a decimal num
 * @arg: argument to be printed
 *
 * Return: number of chars printe
 */

int print_decimal(va_list arg)
{
int i, before, numchars, printed;
double num, after;

num = va_arg(arg, double);
numchars = 0;

if (num == 0)
{
_putchar('0');
return (1);
}

else if (num < 0)
{
_putchar('-');
numchars++;
num = -num;
}

/*whole num before decimal*/
before = (int)num;
numchars += print_int(before);

/*decimal point*/
_putchar('.');
numchars++;

/*fraction after decimal*/
after = num - before;

for (i = 0; i < 6; i++) /*6 digits of precision for float*/
{
after *= 10; /* bring decimal digits before (.) */
printed = (int)after;
_putchar('0' + printed);
numchars++;

after = after - printed; /* remove printed, prep to bring another b4 (.)*/
}
return (numchars);
}
