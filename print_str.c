#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_str - Print a string
 *
 * Description : This function will take an argument from va_arg in printf
 *				 and will print the string to stdout
 *
 * @args: The string inputed to the function
 *
 * Return: The length of the string
 */

int print_str(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL || str[0] == '\0')
	{
		if (str == NULL)
			write(1, "(null)", 6);
	return (str == NULL ? 6 : 0);
	}

	while (str[len])
		len++;

	write(1, str, len);

	return (len);
}
