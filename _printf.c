#include "main.h"
#include "stdarg.h"
#include <unistd.h>

/**
 * _printf - Function that mimic printf
 *
 * Description: This function needs to format an outpu to the stdout using
 *				determined specifiers
 *
 * @format: The formatting of string
 *
 * Return: The number of characters printed
 */

int _printf(const char *format, ...)
{
	int count = 0, index = 0;
	specifier_t specifier[] = { {'c', _putchar}, {'s', print_str},
	{'i', print_dig}, {'d', print_dig} };
	va_list args;

	va_start(args, format);
	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, "%", 1);
				count++;
				format++;
				continue;
			}
			for (index = 0; index < 2; index++)
			if (*format == specifier[index].specifier)
			{
				count += specifier[index].func(args);
				break;
			}
			if (index == 2)
			{
				write(1, "%", 1);
				write(1, format, 1);
				count += 2;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
