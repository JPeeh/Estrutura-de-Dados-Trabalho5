#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};


void append(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

float calcularMedia(struct Node* head) {
    if (head == NULL) {
        return 0.0; 
    }

    int total = 0;
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        total += current->data;
        count++;
        current = current->next;
    }

    return (float)total / count;
}

int main() {
    struct Node* minhaLista = NULL;
    int valor;

    printf("Digite os valores da lista (digite -1 para parar):\n");

    while (1) {
        printf("Digite um valor: ");
        scanf("%d", &valor);
        if (valor == -1) {
            break;
        }
        append(&minhaLista, valor);
    }

    float media = calcularMedia(minhaLista);

    if (media != 0.0) {
        printf("A media dos valores na lista encadeada e: %.2f\n", media);
    } else {
        printf("A lista esta vazia.\n");
    }

    struct Node* current = minhaLista;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}
