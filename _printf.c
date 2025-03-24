#include "main.h"
#include "stdarg.h"

int _printf(const char *format, ...)
{
	int count = 0, index = 0, handle = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			for (index = 0; index < 3; index++)
			
		}
	}
}