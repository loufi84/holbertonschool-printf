#include "main.h"
#include <stdarg.h>

/**
 * print_percent - Prints a percent sign
 * @args: Unused
 * Return: Always 1
 */
int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
