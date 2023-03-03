#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct coche {
    char matricula[8];
    char color[15];
    char marca[20];
    char modelo[20];
    int age;
} Coche;

typedef struct nodo {
    Coche *dato;
    struct nodo *siguiente;
} Nodo;

typedef struct pila {
    Nodo *tope;
    int total;
} Pila;

Coche *crearCoche(char matricula[8], char color[15], char marca[20], char modelo[20], int age) {
    Coche *aux = (Coche*) malloc(sizeof(Coche));
    strcpy(aux->matricula, matricula);
    strcpy(aux->modelo, modelo);
    strcpy(aux->color, color);
    strcpy(aux->marca, marca);
    aux->age = age;
    return aux;
}

Nodo *crearNodo(Coche *coche) {
    Nodo *aux = (Nodo*) malloc(sizeof(Nodo));
    aux->dato = coche;
    aux->siguiente = NULL;
    return aux;
}

Pila *crearPila() {
    Pila *aux = (Pila*) malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;
    return aux;
}

eliminarCoche(Pila *pila) {
    if (pila->tope == NULL) {
        printf("La pila está vacía, no se puede eliminar ningún coche.\n");
    } else {
        Nodo *aux = pila->tope;
        pila->tope = pila->tope->siguiente;
        free(aux->dato);
        free(aux);
        pila->total--;
        printf("Coche eliminado de la pila.\n");
    }
}

mostrarCoches(Pila *pila) {
    if (pila->tope == NULL) {
        printf("La pila está vacía.\n");
    } else {
        Nodo *aux = pila->tope;
        while (aux != NULL) {
            printf("Marca: %s\n", aux->dato->marca);
            printf("Modelo: %s\n", aux->dato->modelo);
            printf("Matrícula: %s\n", aux->dato->matricula);
            printf("Año: %d\n", aux->dato->age);
            printf("Color: %s\n", aux->dato->color);
            aux = aux->siguiente;
        }
    }
}

int main() {
    Pila *pila = crearPila();
    int opcion;
    do {
        printf("\nOpciones:\n");
        printf("1. Agregar coche\n");
        printf("2. Eliminar coche\n");
        printf("3. Mostrar coches en la pila\n");
        printf("4. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1: {
                char matricula[8], color[15], marca[20], modelo[20];
                int age;
                printf("Marca: ");
                scanf("%s", marca);
                printf("Modelo: ");
                scanf("%s", modelo);
                printf("Matrícula: ");
                scanf("%s", matricula);
                printf("Año: ");
                scanf("%d", &age);
                printf("Color: ");
                scanf("%s", color);
                Coche *coche = crearCoche(matricula, color, marca, modelo, age);
                Nodo *nodo = crearNodo(coche);
                nodo->siguiente = pila->tope;
                pila->tope = nodo;
                pila->total++;
                break;
            }
            case 2: {
                eliminarCoche(pila);
            break;
            }
            case 3: {
                mostrarCoches(pila);
            break;
            }
            case 4: {
                printf("Adiós!\n");
            break;
            }
            default: {
                printf("Opción inválida.\n");
            break;
            }
            }
        } while (opcion != 4);
    return 0;
}
