#include "main.h"
#include <unistd.h>

/**
 * print_char - Prints a character
 * @args: The character to print
 * Return: 1 for 1 character
 */

int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	return (_putchar(c));
}
