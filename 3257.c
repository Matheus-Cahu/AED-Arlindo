#include <stdio.h>
#include <stdlib.h>

// Função de comparação para ordenar os tempos em ordem decrescente
int compara(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    scanf("%d", &n);

    int tempos[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &tempos[i]);
    }

    // Ordena os tempos em ordem decrescente
    qsort(tempos, n, sizeof(int), compara);

    int maxDias = 0;
    for (int i = 0; i < n; i++) {
        // Calcula o tempo até cada árvore crescer completamente
        int dias = tempos[i] + i + 1; // Tempo para plantar + crescimento
        if (dias > maxDias) {
            maxDias = dias;
        }
    }

    // Soma 1 dia para a festa ocorrer após o último crescimento
    printf("%d\n", maxDias + 1);

    return 0;
}
