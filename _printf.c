#include "main.h"
#include "stdarg.h"
#include <unistd.h>

/**
 * unrecognized - Handle non recognized specifier
 * @format: The characters to be printed
 * @count: The number of characters printed
 * Return: Nothing
 */

void unrecognized(const char *format, int *count)
{
	write(1, "%", 1);
	write(1, format, 1);
	*count += 2;
}

/**
 * handle_spec - An helper function to help complie to Betty 40 lines
 * @format: The string to check from
 * @args: The args we need to check
 * @count: The number of characters printed
 * Return: 0 on success
 */

int handle_spec(const char *format, va_list args, int *count)
{
	int index;
	specifier_t specifier[] = {
		{'c', _putchar}, {'s', print_str}, {'i', print_dig}, {'d', print_dig}
	};

	for (index = 0; index < 4; index++)
	{
		if (*format == specifier[index].specifier)
		{
			*count += specifier[index].func(args);
			return (1);
		}
	}
	return (0);
}

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
	int count = 0;
	va_list args;

	if (format == NULL)
	return (-1);
	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				write(1, "%", 1);
				count++;
				break;
			}
			if (*format == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (!handle_spec(format, args, &count))
				unrecognized(format, &count);
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
