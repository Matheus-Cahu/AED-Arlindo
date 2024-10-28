#include <stdio.h>

int linhas(int solucao[9][9]){
    int um = 0, dois = 0, tres = 0, quatro = 0, cinco = 0, seis = 0, sete = 0, oito = 0, nove = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (solucao[i][j] == 1) um++;
            else if (solucao[i][j] == 2) dois++;
            else if (solucao[i][j] == 3) tres++;
            else if (solucao[i][j] == 4) quatro++;
            else if (solucao[i][j] == 5) cinco++;
            else if (solucao[i][j] == 6) seis++;
            else if (solucao[i][j] == 7) sete++;
            else if (solucao[i][j] == 8) oito++;
            else if (solucao[i][j] == 9) nove++;
        }
        if( um > 1 || dois > 1 || tres > 1 || quatro > 1 || cinco > 1 || seis > 1 || sete > 1 || oito > 1 || nove > 1){
            return 1;
        }
        um = dois = tres = quatro = cinco = seis = sete = oito = nove = 0;
    }
    return 0;
}

int colunas(int solucao[9][9]){
    int um = 0, dois = 0, tres = 0, quatro = 0, cinco = 0, seis = 0, sete = 0, oito = 0, nove = 0;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if (solucao[j][i] == 1) um++;
            else if (solucao[j][i] == 2) dois++;
            else if (solucao[j][i] == 3) tres++;
            else if (solucao[j][i] == 4) quatro++;
            else if (solucao[j][i] == 5) cinco++;
            else if (solucao[j][i] == 6) seis++;
            else if (solucao[j][i] == 7) sete++;
            else if (solucao[j][i] == 8) oito++;
            else if (solucao[j][i] == 9) nove++;
        }
        if(um > 1 || dois > 1 || tres > 1 || quatro > 1 || cinco > 1 || seis > 1 || sete > 1 || oito > 1 || nove > 1){
            return 1;
        }

        um = dois = tres = quatro = cinco = seis = sete = oito = nove = 0;
    }
    return 0;
}

int regiao(int regiao[3][3]){
    int um = 0, dois = 0, tres = 0, quatro = 0, cinco = 0, seis = 0, sete = 0, oito = 0, nove = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (regiao[i][j] == 1) um++;
            else if (regiao[i][j] == 2) dois++;
            else if (regiao[i][j] == 3) tres++;
            else if (regiao[i][j] == 4) quatro++;
            else if (regiao[i][j] == 5) cinco++;
            else if (regiao[i][j] == 6) seis++;
            else if (regiao[i][j] == 7) sete++;
            else if (regiao[i][j] == 8) oito++;
            else if (regiao[i][j] == 9) nove++;
        }
    }
    if(um > 1 || dois > 1 || tres > 1 || quatro > 1 || cinco > 1 || seis > 1 || sete > 1 || oito > 1 || nove > 1){
        return 1;
    }
    return 0;
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int k = 0; k < n; k++){
        int solucao[9][9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                scanf("%d", &solucao[i][j]);
            }
        }
        int reg1[3][3], reg2[3][3], reg3[3][3], reg4[3][3], reg5[3][3], reg6[3][3], reg7[3][3], reg8[3][3], reg9[3][3];

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                reg1[i][j] = solucao[i][j];
                reg2[i][j] = solucao[i][j + 3];
                reg3[i][j] = solucao[i][j + 6];
                reg4[i][j] = solucao[i + 3][j];
                reg5[i][j] = solucao[i + 3][j + 3];
                reg6[i][j] = solucao[i + 3][j + 6];
                reg7[i][j] = solucao[i + 6][j];
                reg8[i][j] = solucao[i + 6][j + 3];
                reg9[i][j] = solucao[i + 6][j + 6];
            }
        }
        printf("Instancia %d \n",k + 1);
        if (colunas(solucao) == 0 && linhas(solucao) == 0 && regiao(reg1) == 0 && regiao(reg2) == 0 && regiao(reg3) == 0 &&
            regiao(reg4) == 0 && regiao(reg5) == 0 && regiao(reg6) == 0 && regiao(reg7) == 0 && regiao(reg8) == 0 && regiao(reg9) == 0) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }
    return 0;
}
