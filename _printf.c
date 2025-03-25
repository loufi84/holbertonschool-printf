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
	specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_dig},
		{'i', print_dig},
		{'b', print_bin},
		{0, NULL}
	};
	int i;

	if (format[index + 1] == '\0')
		return (-1);

	for (i = 0; specifiers[i].specifier != 0; i++)
	{
		if (format[index + 1] == specifiers[i].specifier)
		{
			*count += specifiers[i].func(args);
			return (index + 1);
		}
	}

	if (format[index + 1] == '%')
	{
		_putchar('%');
		(*count)++;
		return (index + 1);
	}
	_putchar('%');
	_putchar(format[index + 1]);
	*count += 2;
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
