#include <stdio.h>
#include <string.h>

#define MAX_TEXTO 2001

void compactar_texto(char *texto, char *resultado) {
    int i = 0;
    int pos_resultado = 0;
    int tamanho = strlen(texto);
    
    while (i < tamanho) {
        if (texto[i] == '0') {
            int contador = 0;
            int inicio = i;
            
            while (i < tamanho && texto[i] == '0') {
                contador++;
                i++;
            }
            
            if (contador > 2) {
                while (contador > 0) {
                    int bloco = contador > 255 ? 255 : contador;
                    resultado[pos_resultado++] = '#';
                    resultado[pos_resultado++] = (char)bloco;
                    contador -= bloco;
                }
            } else {
                while (inicio < i) {
                    resultado[pos_resultado++] = texto[inicio++];
                }
            }
        }
        else if (texto[i] == ' ') {
            int contador = 0;
            int inicio = i;
            
            while (i < tamanho && texto[i] == ' ') {
                contador++;
                i++;
            }
            
            if (contador > 2) {
                while (contador > 0) {
                    int bloco = contador > 255 ? 255 : contador;
                    resultado[pos_resultado++] = '$';
                    resultado[pos_resultado++] = (char)bloco;
                    contador -= bloco;
                }
            } else {
                while (inicio < i) {
                    resultado[pos_resultado++] = texto[inicio++];
                }
            }
        }
        else {
            resultado[pos_resultado++] = texto[i++];
        }
    }
    
    resultado[pos_resultado] = '\0';
}

int main() {
    int quantidade_casos;
    char texto[MAX_TEXTO];
    char resultado[MAX_TEXTO * 2];
    
    scanf("%d\n", &quantidade_casos);
    
    for (int i = 0; i < quantidade_casos; i++) {
        fgets(texto, MAX_TEXTO, stdin);
        
        int len = strlen(texto);
        if (texto[len-1] == '\n') {
            texto[len-1] = '\0';
        }
        
        compactar_texto(texto, resultado);
        printf("%s\n", resultado);
    }
    
    return 0;
}
