/**
    Suma de numeros enteros usando punteros
**/

#include <stdio.h>

int main()
{
    float num1, num2, sum, rest, mult, div;
    float *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    printf("Digite cualquier numero: ");
    scanf("%f", ptr1);
    printf("Digite cualquier numero: ");
    scanf("%f", ptr2);


    sum  = (*ptr1) + (*ptr2);
    rest = (*ptr1) - (*ptr2);
    mult = (*ptr1) * (*ptr2);
    div  = (*ptr1) / (*ptr2);

    /* Print the results */
    printf("Suma = %.2f\n", sum);
    printf("Diferencia = %.2f\n", rest);
    printf("Producto = %.2f\n", mult);
    printf("Cociente = %.2f\n", div);

    return 0;
}
