/*
    Programa para sumar dos matrcies de 3*3
*/

#include <stdio.h>

#define ROWS 3
#define COLS 3


void entradamatriz(int mat[][COLS]);
void mostrarmatriz(int mat[][COLS]);
void sumamatriz(int mat1[][COLS], int mat2[][COLS], int res[][COLS]);


int main()
{
    int mat1[ROWS][COLS], mat2[ROWS][COLS], res[ROWS][COLS];

    printf("Digite los elementos de la primera matriz %dx%d: \n", ROWS, COLS);
    entradamatriz(mat1);

    printf("\nDigite los elementos de la segunda matriz %dx%d: \n", ROWS, COLS);
    entradamatriz(mat2);

    sumamatriz(mat1, mat2, res);

    printf("\n Suma de las matrices: \n");
    mostrarmatriz(res);


    return 0;
}

void entradamatriz(int mat[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            scanf("%d", (*(mat + i) + j));
        }
    }
}

void mostrarmatriz(int mat[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            printf("%d ", *(*(mat + i) + j));
        }
        printf("\n");
    }
}

void sumamatriz(int mat1[][COLS], int mat2[][COLS], int res[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            *(*(res + i) + j) = *(*(mat1 + i) + j) + *(*(mat2 + i) + j);
        }
    }
}
