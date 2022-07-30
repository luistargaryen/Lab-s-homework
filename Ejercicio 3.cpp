/*
  Programa en C para invertir el orden de los elementos en un array
 */
#include <stdio.h>
#define MAX_SIZE 100

void printArr(int *arr, int noelementos);

int main()
{
    int arr[MAX_SIZE];
    int noelementos;
    int *left = arr;
    int *right;

    printf("Digite el numero de elementos del array: ");
    scanf("%d", &noelementos);

    right = &arr[noelementos - 1];

    printf("Digite los elementos del array: ");
    while(left <= right)
    {
        scanf("%d", left++);
    }


    printf("\nEl array antes de invertir su orden original: ");
    printArr(arr, noelementos);

    left = arr;

    while(left < right)
    {

        *left    ^= *right;
        *right   ^= *left;
        *left    ^= *right;

        left++;
        right--;
    }


    printf("\nArray despues de invertirlo: ");
    printArr(arr, noelementos);


    return 0;
}

/*Funcion para imprimir arrays*/

void printArr(int *arr, int noelementos)
{
    int *arrEnd = (arr + noelementos - 1);

    while(arr <= arrEnd)
    {
        printf("%d, ", *arr);
        arr++;
    }
}
