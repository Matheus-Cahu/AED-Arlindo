#include <stdio.h>

int verifica_linhas(int solucao[9][9]) {
    for (int i = 0; i < 9; i++) {
        int numeros[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = solucao[i][j];
            if (num < 1 || num > 9 || numeros[num] == 1) return 1;
            numeros[num] = 1;
        }
    }
    return 0;
}

int verifica_colunas(int solucao[9][9]) {
    for (int i = 0; i < 9; i++) {
        int numeros[10] = {0};
        for (int j = 0; j < 9; j++) {
            int num = solucao[j][i];
            if (num < 1 || num > 9 || numeros[num] == 1) return 1;
            numeros[num] = 1;
        }
    }
    return 0;
}

int verifica_regiao(int solucao[9][9], int inicio_i, int inicio_j) {
    int numeros[10] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = solucao[inicio_i + i][inicio_j + j];
            if (num < 1 || num > 9 || numeros[num] == 1) return 1;
            numeros[num] = 1;
        }
    }
    return 0;
}

int verifica_todas_regioes(int solucao[9][9]) {
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (verifica_regiao(solucao, i, j)) return 1;
        }
    }
    return 0;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int k = 0; k < n; k++) {
        int solucao[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &solucao[i][j]);
            }
        }

        printf("Instancia %d\n", k + 1);
        if (verifica_linhas(solucao) == 0 && verifica_colunas(solucao) == 0 && verifica_todas_regioes(solucao) == 0) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
