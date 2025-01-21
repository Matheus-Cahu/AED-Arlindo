#include <stdio.h>

int main(){
    int gab, certos = 0;
    int resp[5];
    scanf("%d", &gab);
    scanf("%d %d %d %d %d", &resp[0], &resp[1], &resp[2], &resp[3], &resp[4]);
    for(int i=0; i<5; i++){
        if(resp[i] == gab) certos++;
    }
    printf("%d\n", certos);
}