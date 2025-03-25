#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_str(va_list args);
int print_dig(va_list args);
int print_char(va_list args);
int print_percent(void);

/**
 * struct specifier_t - A data structure linking specifiers with functions
 * @specifier: The specifier selected by the user
 * @func: The function used to format the output
 */

typedef struct specifier_t
{
	char specifier;
	int (*func)(va_list);
} specifier_t;


#endif /* MAIN_H */
