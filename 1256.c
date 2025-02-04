#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

typedef struct Node_Head{
    int value;
    Node *next;
    struct Node_Head *next_head;
}Node_Head;

Node *createNode(int value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

Node_Head *create_Head(int value) {
    Node_Head *newHead = (Node_Head *)malloc(sizeof(Node_Head));
    if (newHead == NULL) {
        printf("Erro: Memória insuficiente!\n");
        exit(1);
    }
    newHead->value = value;
    newHead->next = NULL;
    newHead->next_head = NULL;
    return newHead;
}

void addHead(int value, Node_Head *head) {
    Node_Head *current = head;
    while (current->next_head != NULL) {
        current = current->next_head;
    }
    current->next_head = create_Head(value);
}

void addNode(int value, Node_Head *head){
    if(head->next == NULL){
        head->next = createNode(value);
    }else{
        Node *atual = head->next;
        while(atual->next != NULL){
            atual = atual->next;
        }
        atual->next = createNode(value);
    }
}

Node_Head *findHead(int value, Node_Head *head) {
    Node_Head *atual = head;
    while (atual != NULL && atual->value != value) {
        atual = atual->next_head;
    }
    return atual; // Retorna NULL se não encontrar
}


void printList(Node_Head *head) {
    Node *atual = head->next;
    if (atual == NULL) {
        return;
    }
    while (atual->next != NULL) {
        printf("%d -> ", atual->value);
        atual = atual->next;
    }
    printf("%d -> \\", atual->value);
}

void printHeads(Node_Head *head) {
    Node_Head *atual = head;
    while (atual != NULL) {
        printf("%d -> ", atual->value);
        printList(atual);
        printf("\n");
        atual = atual->next_head;
    }
}



int main(){
    //número de testes
    int nr_testes;
    scanf("%d", &nr_testes);
    for(int i=0; i<nr_testes; i++){
        Node_Head *head = create_Head(0);
        int mod, casos;
    //scan parametros
    scanf("%d %d", &mod, &casos);
    for(int k = 0; k<mod; k++){
        addHead(k, head);
    }
    for(int k=0; k<casos; k++){
        int n;
        scanf("%d", &n);
        addNode(n, findHead(n%mod, head));
    }
    printHeads(head);

    }

    return 0;
}
