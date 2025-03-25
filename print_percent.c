#include "main.h"
#include <unistd.h>

/**
 * print_percent - Prints a percent sign
 * @args: Arguments list (unused)
 * Return: Always 1
 */
int print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
