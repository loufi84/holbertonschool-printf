#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _print_str(va_list args);

/**
 * struct specifier_t - The data structure used to link specifiers to functions
 *
 * @specifier: The specifier to check
 *
 * @func: The function to used when specifier match
 */

typedef struct specifier_t
{
	char specifier;
	int (*func)(va_list args);
} specifier_t;


#endif /* MAIN_H */
