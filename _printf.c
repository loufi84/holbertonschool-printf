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

int handle_specifier(const char *format, va_list args, int index)
{
	static const specifier_t specifiers[] = {
		{'c', print_char},
		{'s', print_str},
		{'d', print_dig},
		{'i', print_dig},
		{'%', print_percent}
	};
	int i;

	if (format[index + 1] == '\0')
		return (-1);

	for (i = 0; i < sizeof(specifiers) / sizeof(specifiers[0]); i++)
	{
		if (format[index + 1] == specifiers[i].specifier)
			return (specifiers[i].func(args));
	}
	_putchar('%');
	_putchar(format[index + 1]);
	return (2);
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
	int add_count = 0;

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
			add_count = handle_specifier(format, args, index);
			if (add_count == -1)
			{
				va_end(args);
				return (-1);
			}
			count += add_count;
			index++;
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
