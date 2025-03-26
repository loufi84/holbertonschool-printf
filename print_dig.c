#include "main.h"
#include <stdarg.h>
#include <unistd.h>


/**
 * print_dig - Prints an integer to standard output.
 * @args: A va_list containing the integer to print.
 *
 * Description:
 * This function extracts an integer from the variable arguments list,
 * converts it into a string representation, and writes it to the
 * standard output. It handles negative numbers
 * by printing a '-' sign before the absolute value.
 *
 * Return: The number of characters printed.
 */

int print_dig(va_list args)
{
char buffer[12];
int count = 0, index = 0, n = va_arg(args, int);
unsigned int num;
if (n == 0)
{
write(1, "0", 1);
count++;
return (count);
}
if (n == -2147483648)
{
write(1, "-2147483648", 11);
return (11);
}
if (n < 0)
{
write(1, "-", 1);
count++;
num = -n;
}
else
	num = n;
while (num > 0)
{
buffer[index++] = num % 10 + '0';
num /= 10;
}
count += index;
while (index > 0)
	write(1, &buffer[--index], 1);
return (count);
}
