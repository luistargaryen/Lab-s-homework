/*
    Programa para saber la longitud de una cadena
 */

#include <stdio.h>
#define MAX_SIZE 100

int main()
{
    char text[MAX_SIZE];
    char *str = text;
    int i = 0;

    /* Input string from user */
    printf("Digite cualquier cadena: ");
    gets(text);

    /* Iterate though last element of the string */
    while(*(str++) != '\0') i++;

    printf("Longitud de '%s' es de %d caracteres", text, i);

    return 0;
}
