#include <stdio.h>
#include <string.h>

int main(){
    int k;
    scanf("%d", &k);
    getchar();
    for(int j = 0; j<k; j++){
    char line[1000];
    fgets(line, 1000, stdin);

    int diamantes = 0;
    int abre = 0;

    for(int i = 0; i<strlen(line) + 1; i++){
        if(line[i] == '<')abre++;
        else if(line[i] == '>'){
            if(abre > 0){
                abre--;
                diamantes++;
            }
        }
    }
    printf("%d\n", diamantes);
    }
    return 0;
}