#include <stdio.h>
#include <stdlib.h>

// Função para calcular o maior entre dois números usando a fórmula
int maior(int a, int b) {
    return (a + b + abs(a - b)) / 2;
}

int main() {
    int a, b, c;

    // Lê os três valores
    scanf("%d %d %d", &a, &b, &c);

    // Calcula o maior entre a e b, depois entre o resultado e c
    int maiorValor = maior(maior(a, b), c);

    // Exibe o maior valor seguido da mensagem
    printf("%d eh o maior\n", maiorValor);

    return 0;
}
