#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    struct Node *next;
} Node;

Node* createNode(int id) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->next = NULL;
    return newNode;
}

void addNode(Node **head, int id) {
    Node *newNode = createNode(id);

    // Se a lista está vazia, adiciona o primeiro nó
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Percorre até o final da lista
    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void removeNode(Node **head, int id) {
    if (*head == NULL) {
        return;
    }

    Node *current = *head;
    Node *previous = NULL;

    if (current->id == id) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        previous->next = current->next;
        free(current);
    }
}

void printList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->id);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int id;
        scanf("%d", &id);
        addNode(&head, id);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int id;
        scanf("%d", &id);
        removeNode(&head, id);
    }

    printList(head);
    printf("\n");
    return 0;
}
