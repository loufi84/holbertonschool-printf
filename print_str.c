#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/* Inclusion du fichier d'en-tête contenant les déclarations des fonctions */
/* Inclusion de la bibliothèque pour gérer les arguments variables */
/* Inclusion de la bibliothèque pour la fonction write */

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
/* Compteur pour la longueur de la chaîne */
	int len = 0;
/* Récupération de la chaîne depuis la liste d'arguments */
	char *str = va_arg(args, char *);
/* Si la chaîne est NULL, on remplace par "(null)" */
	if (str == NULL)
		str = "(null)";
/* Boucle pour afficher chaque caractère de la chaîne */
	while (str[len])
	{
/* Affichage du caractère courant */
		_putchar(str[len]);
/* Incrémentation du compteur de longueur */
		len++;
	}
/* Retourne la longueur de la chaîne */
	return (len);
}
