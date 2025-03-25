#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * unrecognized - Handles unknown specifiers
 * @format: The specifier character
 * @count: Pointer to character count
 */
void unrecognized(const char *format, int *count)
{
	write(1, "%", 1);
	write(1, format, 1);
	*count += 2;
}

/**
 * handle_spec - Processes format specifiers
 * @format: The specifier character
 * @args: Arguments list
 * @count: Pointer to character count
 * Return: 1 if specifier handled, 0 otherwise
 */
int handle_spec(const char *format, va_list args, int *count)
{
	int i;
	specifier_t specs[] = {
		{'c', _putchar}, {'s', print_str}, {'i', print_dig}, {'d', print_dig}
	};

	for (i = 0; i < 4; i++)
	{
		if (*format == specs[i].specifier)
		{
			va_list copy;

			va_copy(copy, args);
			*count += specs[i].func(copy);
			va_end(copy);
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

	if (!format)
		return (-1);

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				break;

			if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else
			{
				va_list copy;

				va_copy(copy, args);
				if (!handle_spec(format, copy, &count))
					unrecognized(format, &count);
				va_end(copy);
				va_arg(args, void *);
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
