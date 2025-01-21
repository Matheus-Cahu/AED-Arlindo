#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n); // Lê o tamanho da sequência

    int sequencia[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequencia[i]); // Lê a sequência de números
    }

    // Variável para contar o máximo de números marcados
    int maxMarcados = 1; // O primeiro número sempre pode ser marcado

    for (int i = 1; i < n; i++) {
        // Só podemos marcar se o número atual for diferente do anterior
        if (sequencia[i] != sequencia[i - 1]) {
            maxMarcados++;
        }
    }

    printf("%d\n", maxMarcados); // Imprime o número máximo de números marcados

    return 0;
}
