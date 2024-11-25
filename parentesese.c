#include <stdio.h>
#include <string.h>

int main() {
    int k;
    scanf("%d", &k);
    getchar();
    for(int j = 0; j<k; j++){
    char line[1000];
    int abre = 0, fecha = 0;
    fgets(line, 1000, stdin);

    for (int i = 0; i < strlen(line) - 1; i++) {
        if (line[i] == '(') {
            abre++;
        } else if (line[i] == ')') {
            if (abre > fecha) {
                fecha++;
            } else {
                printf("Incorrect\n");
            }
        }
    }

    if (abre == fecha) {
        printf("Correct\n");
    } else {
        printf("Incorrect\n");
    }
}
printf("\n");
    return 0;
}