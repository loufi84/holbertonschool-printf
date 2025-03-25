#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - Processes single format specifier
 * @spec: The specifier character
 * @args: Arguments list
 * @count: Pointer to character count
 * Return: 1 if processed, 0 otherwise
 */
static int handle_specifier(char spec, va_list args, int *count)
{
	int i;
	specifier_t specs[] = {
		{'c', print_char}, {'s', print_str},
		{'d', print_dig}, {'i', print_dig}, {'%', print_percent}
	};


	for (i = 0; i < 5; i++)
	{
		if (spec == specs[i].specifier)
		{
			int printed = specs[i].func(args);

			if (printed == -1)
			{
				return (0);
			}
			*count += printed;
			return (1);
		}
	}
	return (0);
}


/**
 * _printf - Produces output according to format
 * @format: Format string
 * Return: Number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (*format + 1 == '\0')
			{
				va_end(args);
				return (-1);
			}
			handle_specifier(*format, args, &count);
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
