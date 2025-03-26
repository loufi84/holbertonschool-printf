#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * handle_specifier - selectionner le specifier
 * @format: chaine de caractères
 * @args: arguments
 * @index: position
 * @count: nombre de caractères
 * Return: nouvelle position
 */


int handle_specifier(const char *format, va_list args, int index, int *count)
/*Définition d'un tableau de structures contenant les spécificateurs de */
/* format et leur fonction associée */
{
	specifier_t specifiers[] = {
{'c', print_char}, /* %c pour afficher un caractère*/
{'s', print_str}, /* %s pour afficher une chaîne de caractères*/
{'d', print_dig}, /* %d pour afficher un entier signé */
{'i', print_dig}, /* %i pour afficher un entier signé (équivalent à %d) */
};
int i;

 /* Vérifie si l'index suivant est vide */
if (format[index + 1] == '\0')
return (-1); /* Retourne -1 pour signaler une erreur */

/* Parcours du tableau de spécificateurs pour voir si le caractère */
/* après % correspond à un spécificateur */
for (i = 0; i < 4; i++)
{
if (format[index + 1] == specifiers[i].specifier)
{
*count += specifiers[i].func(args); /* Appel de la bonne fonction */
return (index + 1); /* Retourne l'index du caractère traité */
}
}

/* Si le caractère après % est aussi un %, on imprime un seul % */
if (format[index + 1] == '%')
{
_putchar('%'); /* Affiche un % */
(*count)++; /* Incrémente le compteur */
return (index + 1); /* Retourne l'index du caractère traité */
}
 /* Si le caractère après % ne correspond à aucun spécificateur connu */
_putchar('%'); /* Affiche le % initial */
_putchar(format[index + 1]); /* Affiche le caractère inconnu tel quel */
*count += 2; /* Incrémente le compteur de 2 */
return (index + 1); /* Retourne l'index du caractère traité */
}

/**
 * _printf - affiche une chaine formaté
 * @format: chaine de texte + formats
 * Return: le nombre de caractères affiché
 */

int _printf(const char *format, ...)
{
va_list args; /* Définition d'une liste nommée args */
int index = 0, count = 0;

/* Vérifie si la chaîne format est NULL */
if (format == NULL)
return (-1);

va_start(args, format); /* Initialise la liste */
while (format[index])
{
/* Vérifie si le caractère actuel est un % */
if (format[index] == '%')
{
if (format[index + 1] == '\0')
{
/* Vérifie si % est le dernier caractère de la chaîne */
va_end(args);
return (-1);
}
/* Gère le spécificateur et met à jour l'index */
index = handle_specifier(format, args, index, &count);
}
else
{
_putchar(format[index]); /* Affiche le caractère normal */
count++;
}
index++;
}
va_end(args);
return (count); /* Retourne le nombre total de caractères imprimés */
}
