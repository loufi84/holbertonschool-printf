#ifndef MAIN_H
#define MAIN_H
/* Vérifie si MAIN_H n'a pas encore été */
/* Défini pour éviter les inclusions multiples */

/* Inclusion de la bibliothèque pour gérer*/
/*les arguments variables */
#include <stdarg.h>

/* Déclaration des fonctions */

/* Fonction principale qui imite printf */
int _printf(const char *format, ...);
/* Fonction pour afficher un seul caractère */
int _putchar(char c);
/* Fonction pour afficher une chaîne de caractères */
int print_str(va_list args);
/* Fonction pour afficher un entier */
int print_dig(va_list args);
/* Fonction pour afficher un caractère */
int print_char(va_list args);


/**
 * struct specifier_t - A data structure linking specifiers with functions
 * @specifier: The specifier selected by the user
 * @func: The function used to format the output
 */

 /* Création d'une structure pour contenir les spécificateurs */
 /* Et les lier aux fonctions adéquates */
typedef struct specifier_t
{
/* Spécificateur de format*/
char specifier;
/* Pointeur vers la fonction qui gère ce spécificateur */
int (*func)(va_list);
} specifier_t;

/* Fin de la directive de préprocesseur */
#endif /* MAIN_H */
