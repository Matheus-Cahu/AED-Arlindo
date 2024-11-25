#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[20];
    struct aluno *next;
} aluno;

aluno* createAluno(char nome[20]) {
    aluno *newAluno = (aluno*)malloc(sizeof(aluno));
    strcpy(newAluno->nome, nome);
    newAluno->next = NULL;
    return newAluno;
}

void addAluno(aluno **head, char nome[20]) {
    aluno *newAluno = createAluno(nome);

    if (*head == NULL || strcmp(newAluno->nome, (*head)->nome) < 0) {
        newAluno->next = *head;
        *head = newAluno;
        return;
    }

    aluno *current = *head;
    while (current->next != NULL && strcmp(newAluno->nome, current->next->nome) > 0) {
        current = current->next;
    }
    newAluno->next = current->next;
    current->next = newAluno;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    getchar(); 

    aluno *head = NULL;

    for (int i = 0; i < n; i++) {
        char nome[20];
        fgets(nome, 20, stdin);
        nome[strcspn(nome, "\n")] = 0;
        addAluno(&head, nome);
    }

    aluno *current = head;
    for (int i = 0; i < k-1; i++) {
        current = current->next;
    }
    printf("%s", current->nome);
    return 0;
}
