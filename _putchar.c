#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a single character
 * @args: character to be printed
 * Return: a character to standard output (stdout)
 */

int _putchar(va_list args)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	return (1);
}
