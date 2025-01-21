#include <stdio.h>

int main() {
    double A, B;

    // Lê os dois valores com uma casa decimal
    scanf("%lf %lf", &A, &B);

    // Calcula a média ponderada
    double MEDIA = (A * 3.5 + B * 7.5) / 11.0;

    // Imprime a média com o formato correto
    printf("MEDIA = %.5lf\n", MEDIA);

    return 0;
}
