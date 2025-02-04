#include <stdio.h>
#include <stdlib.h>

typedef struct Carro {
    int chegada;
    int saida;
    struct Carro *next;
} Carro;

Carro* createCarro(int chegada, int saida) {
    Carro *newCarro = (Carro*)malloc(sizeof(Carro));
    newCarro->chegada = chegada;
    newCarro->saida = saida;
    newCarro->next = NULL;
    return newCarro;
}

void addCarro(Carro **head, int chegada, int saida) {
    Carro *newCarro = createCarro(chegada, saida);
    if (*head == NULL || (*head)->chegada > newCarro->chegada) {
        // Inserção no início da lista
        newCarro->next = *head;
        *head = newCarro;
    } else {
        // Inserção ordenada por chegada
        Carro *current = *head;
        while (current->next != NULL && current->next->chegada < newCarro->chegada) {
            current = current->next;
        }
        newCarro->next = current->next;
        current->next = newCarro;
    }
}

int verificarHora(Carro *head) {
    Carro *current = head;
    
    while (current != NULL) {
        Carro *temp = current->next;
        while (temp != NULL) {
            if (temp->saida < current->saida) {
                return 1;  // Há um bloqueio de saída
            }
            temp = temp->next;
        }
        current = current->next;
    }
    return 0;  // Nenhum bloqueio de saída encontrado
}

int verificarNr(Carro *head, int k) {
    Carro *current = head;
    
    while (current != NULL) {
        int atual = 0;  // Contador de carros simultâneos
        Carro *temp = head;
        
        while (temp != NULL) {
            // Verifica se o carro `temp` está no estacionamento ao mesmo tempo que `current`
            if (temp->chegada <= current->chegada && temp->saida > current->chegada) {
                atual++;
            }
            temp = temp->next;
        }
        
        printf("A quantidade de carros simultâneos é %d \n", atual);
        if (atual > k) return 1;  // Se o limite de `k` for ultrapassado, retorna 1
        
        current = current->next;
    }
    return 0;  // Retorna 0 se o limite de carros simultâneos não foi ultrapassado
}

void printLista(Carro *head) {
    Carro *current = head;
    while (current != NULL) {
        printf("\n%d %d", current->chegada, current->saida);
        current = current->next;
    }
}

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);
    
    Carro *head = NULL;
    
    for (int i = 0; i < n; i++) {
        int ci, si;
        scanf("%d %d", &ci, &si);
        addCarro(&head, ci, si);
    }
    
    if (verificarHora(head) == 1) {
        printf("Não");
    } else if (verificarNr(head, k) == 1) {
        printf("Não");
    } else {
        printf("Sim");
    }
    
    printLista(head);
    
    return 0;
}
