#include <stdio.h>
#include <stdlib.h>

// Definir la estructura de nodo para la lista enlazada
struct Node {
    int data;
    struct Node* next;
};

// Función para imprimir los elementos de la lista enlazada
void printList(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
}

int main() {
    int num;
    struct Node* head = NULL;
    struct Node* current = NULL;
    struct Node* new_node = NULL;

    // Solicitar los números de identificación y agregarlos a la lista enlazada
    while (1) {
        printf("Ingrese un número de identificación (o -1 para terminar): ");
        scanf("%d", &num);
        if (num == -1) {
            break;
        }
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = num;
        new_node->next = NULL;
        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = new_node;
        }
    }

    // Imprimir los elementos de la lista enlazada
    printList(head);

    return 0;
}
