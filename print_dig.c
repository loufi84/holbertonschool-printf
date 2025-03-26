#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/* Inclusion du fichier d'en-tête contenant les déclarations des fonctions */
/* Inclusion de la bibliothèque pour gérer les arguments variables */
/* Inclusion de la bibliothèque pour la fonction write */

/**
 * print_dig - Prints an integer to standard output.
 * @args: A va_list containing the integer to print.
 *
 * Description:
 * This function extracts an integer from the variable arguments list,
 * converts it into a string representation, and writes it to the
 * standard output. It handles negative numbers
 * by printing a '-' sign before the absolute value.
 *
 * Return: The number of characters printed.
 */


int print_dig(va_list args)
{
/* Tableau pour stocker les chiffres de l'entier */
char buffer[12];
/* Extraction de l'entier depuis la liste d'arguments */
int count = 0, index = 0, n = va_arg(args, int);
/* Variable pour stocker la valeur absolue de l'entier */
unsigned int num;
/* Cas particulier : si n vaut 0, on écrit directement '0' */
if (n == 0)
{
write(1, "0", 1);
count++;
return (count);
}
/* Cas particulier : gestion de l'entier minimal -2147483648 */
if (n == -2147483648)
{
write(1, "-2147483648", 11);
return (11);
}
/* Gestion des nombres négatifs */
if (n < 0)
{
write(1, "-", 1);
count++;
/* Conversion en positif */
num = -n;
}
else
	num = n;
/* Extraction des chiffres un par un en partant de la fin */
while (num > 0)
{
/* Conversion du chiffre en caractère */
buffer[index++] = num % 10 + '0';
num /= 10;
}
count += index;
while (index > 0)
write(1, &buffer[--index], 1);
return (count);
}
