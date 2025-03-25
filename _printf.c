#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Select the specifier
 * @format: string
 * @args: arguments
 * @index: position
 * @count: character count
 * Return: New position
 */

int handle_specifier(const char *format, va_list args, int index, int *count)
{
	if (format[index + 1] == 'c')
		*count += print_char(args);
	else if (format[index + 1] == 's')
		*count += print_str(args);
	else if (format[index + 1] == '%')
		*count += print_percent();
	else if (format[index + 1] == 'd' || format[index + 1] == 'i')
		count += print_dig(args);

	else
	{
		_putchar('%');
		_putchar(format[index + 1]);
		*count += 2;
	}
	return (index + 1);
}

/**
 * _printf - print a formated string
 * @format: string of text + formats
 * Return: the number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int index = 0, count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format[index])
	{
		if (format[index] == '%')
		{
			if (format[index + 1] == '\0')
			{
				va_end(args);
				return (-1);
			}
			index = handle_specifier(format, args, index, &count);
		}
		else
		{
			_putchar(format[index]);
			count++;
		}
		index++;
	}
	va_end(args);
	return (count);
}
