#include "main.h"
#include <unistd.h>
/* Inclusion du fichier d'en-tête contenant les déclarations des fonctions */
/* Inclusion de la bibliothèque pour la fonction write */

/**
 * print_char - Prints a character
 * @args: The character to print
 * Return: 1 for 1 character
 */

int print_char(va_list args)
{
/* Extraction du caractère depuis la liste d'arguments */
	char c = (char)va_arg(args, int);

/* Appel de _putchar pour afficher le caractère */
	return (_putchar(c));
}
