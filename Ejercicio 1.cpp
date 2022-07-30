/**
 Programa basico en C para obtener las direcciones de memoria de distintos
 tipos de datos
 **/
#include <stdio.h>

int main()
{
    char caracter = 'C';
    int entero = 1;
    float real = 10.4;
    long long enterogrande = 989898989ll;

    printf("Caracter = %c, Direccion del caracter = %u\n", caracter, &caracter);
    printf("Entero = %d, Direccion del entero = %u\n", entero, &entero);
    printf("Real = %f, Direccion del numero Real = %u\n", real, &real);
    printf("Entero(grande) = %lld, Direccion del entero grande = %u", enterogrande, &enterogrande);

    return 0;
}
