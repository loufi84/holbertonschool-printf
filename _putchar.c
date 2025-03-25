#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a single character
 * @c: character to be printed
 * Return: a character to standard output (stdout)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
