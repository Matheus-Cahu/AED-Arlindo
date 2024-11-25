#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_LENGTH 21

typedef struct Node{
    char item[MAX_ITEM_LENGTH];
    struct Node *next;
} Node;

Node* createNode(char *item) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->item, item);
    newNode->next = NULL;
    return newNode;
}

void addItem(Node **head, char *item) {
    Node *current = *head;
    while(current != NULL) {
        if(strcmp(current->item, item) == 0) {
            return;
        }
        current = current->next;
    }

    Node *newNode = createNode(item);
    
    if(*head == NULL || strcmp((*head)->item, item) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while(current->next != NULL && strcmp(current->next->item, item) < 0) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}


void printList(Node *head){
    Node *current = head;
    while(current != NULL){
        printf("%s", current->item);
        if(current->next != NULL){
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

void freeList(Node *head){
    Node *temp;
    while (head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    getchar();
    for(int i = 0; i < N; i++){
        char line[1001];
        fgets(line, sizeof(line), stdin);
        line[strcspn(line, "\n")] = 0;
        Node *head = NULL;
        char *item = strtok(line, " ");
        while (item != NULL){
            addItem(&head, item);
            item = strtok(NULL, " ");
        }
        printList(head);
        freeList(head);
    }

    return 0;
}