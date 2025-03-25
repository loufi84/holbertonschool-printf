#include "main.h"
#include <stdio.h>

int main(void)
{
	int count;

	count = _printf("%");
	printf("%d\n", count);

	count = _printf("");
	printf("%d\n", count);

	count = _printf("%z");
	printf("%d\n", count);

	count = _printf("%s", NULL);
	printf("%d\n", count);

	count = _printf("%%c%%s\n");
	printf("%d\n", count);

	count = _printf("Hello %s%c%%%d!", "World", '!', 42);
	printf("%d\n", count);

	count = _printf("\n");
	printf("%d\n", count);

	count = _printf("Hello %s!\n", "World");
	printf("%d\n", count);

	count = _printf("Character: %c\n", '!');
	printf("%d\n", count);

	count = _printf("Percent: %%\n");
	printf("%d\n", count);

	count = _printf("%b\n", 98);
	printf("%d\n", count);
}
