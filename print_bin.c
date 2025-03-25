#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_bin_rec - to fill
 * @n: todo
 * Return: todo
 */
static int print_bin_rec(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_bin_rec(n / 2);
	char c = (n % 2) + '0';
	write(1, &c, 1);
	count++;

	return (count);
}

/**
 * print_bin - todo
 * @args: todo
 * Return: todo
 */
int print_bin(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (print_bin_rec(n));
}
