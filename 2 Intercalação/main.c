#include <stdio.h>
#include <stdlib.h>
#define max 10000

int main(){
    int k, i, f;//i numero de iteracoes; k numero de termos

    scanf("%d", &k);
    scanf("%d", &i);

    int matriz[k][max];

    f = 0;

    for(int j = 0; j < k; j++){
        for(i = 0; i < f; i++){
            scanf("%d", f);
            scanf("%d", &matriz[j][i]);
        }
    }


    return 0;
}
