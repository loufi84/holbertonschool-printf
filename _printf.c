#include "main.h"
#include "stdarg.h"

int _printf(const char *format, ...)
{
	int count = 0, index = 0, handle = 0;

	specifier_t specifier[] = {
		{'c', _putchar},
		{'%', _putchar},
		{'s', print_str}
	};

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (index = 0; index < 3; index++)
			if (*format == specifier[index].specifier)
			{
				count += specifier[index].func(args);
				handle = 1;
				break;
			}
			if (!handle)
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
