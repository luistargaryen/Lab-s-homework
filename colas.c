//Luis Vargas
//30833554
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_NOMBRE 50
#define MAX_COLA 100

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
    float salario;
} Empleado;

typedef struct nodo {
    Empleado empleado;
    struct nodo *sig;
} Nodo;

typedef struct {
    Nodo *primero;
    Nodo *ultimo;
    int tamano;
} Cola;

Nodo *crearNodo(Empleado empleado) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    nuevo->empleado = empleado;
    nuevo->sig = NULL;
    return nuevo;
}

Cola *crearCola() {
    Cola *c = (Cola *)malloc(sizeof(Cola));
    c->primero = c->ultimo = NULL;
    c->tamano = 0;
    return c;
}

void enQueue(Empleado empleado, Cola *c) {
    Nodo *nuevo = crearNodo(empleado);
    if (c->primero == NULL) {
        c->primero = c->ultimo = nuevo;
    } else {
        c->ultimo->sig = nuevo;
        c->ultimo = nuevo;
    }
    c->tamano++;
}

Empleado deQueue(Cola *c) {
    if (c->primero == NULL) {
        Empleado vacio = {"", 0, 0};
        return vacio;
    }

    Nodo *eliminado = c->primero;
    Empleado empleado = eliminado->empleado;

    c->primero = eliminado->sig;
    if (c->primero == NULL) {
        c->ultimo = NULL;
    }

    free(eliminado);
    c->tamano--;

    return empleado;
}

void mostrar(Cola *c) {
    printf("Elementos de la cola:\n");

    Nodo *actual = c->primero;
    while (actual != NULL) {
        printf("%s (%d años) - $%.2f\n", actual->empleado.nombre, actual->empleado.edad, actual->empleado.salario);
        actual = actual->sig;
    }

    printf("\n");
}

int main() {
    Cola *c = crearCola();

    // Agregar elementos a la cola
    Empleado e1 = {"Juan Perez", 28, 2500.0};
    Empleado e2 = {"Maria Rodriguez", 32, 3000.0};
    Empleado e3 = {"Pedro Gomez", 22, 2000.0};
    Empleado e4 = {"Ana Martinez", 26, 2200.0};

    enQueue(e1, c);
    enQueue(e2, c);
    enQueue(e3, c);
    enQueue(e4, c);

    // Mostrar elementos de la cola
    mostrar(c);

    // Borrar elementos de la cola
    printf("Eliminando elementos de la cola:\n");

    while (c->tamano > 0) {
        Empleado eliminado = deQueue(c);
        if (strlen(eliminado.nombre) > 0) {
            printf("Eliminado: %s (%d años) - $%.2f\n", eliminado.nombre, eliminado.edad, eliminado.salario);
        } else {printf("La cola está vacía\n");
            }
    }
    return 0;
}
