#include "main.h"
#include <unistd.h>

/**
* _putchar - prints a single character
* @c: character to be printed
* Return: a character to standard output (stdout)
*/

int _putchar(char c)
{
/* Utilisation de la fonction write pour écrire un caractère */
/*sur la sortie standard */
	return (write(1, &c, 1));
}
