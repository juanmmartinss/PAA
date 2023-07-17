#include <stdlib.h>
#include <stdio.h>


int main(){
    int k,n, t;
    int vetpesos[n];
    int vetvalores[n];
    int recebe;
    int matriz[n][k];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            matriz[i][j] = -1;
        }
    }

    while(t--){
        for(int i = 0; i < n; i++){
            scanf("%d", &vetpesos[i]);
            scanf("%d", &vetvalores[i]);
        }
        recebe = solve(k, n, vetpesos, vetvalores, matriz);
    }

    printf("%d", recebe);


    return 0;
}

int solve(int k, int n, int vetpesos[], int vetvalores[], int matriz[n][k]){
    if(n == 0 || k == 0){
        return 0;
    }
    if(matriz[n][k] != -1){
        return matriz[n][k];
    }
    else{
        int opt1 = 0;
        int opt2 = 0;
        
        if(k-vetpesos[n] >= 0){
            opt1 = vetvalores[n] + solve(k-vetpesos[n], n-1, vetpesos, vetvalores, matriz);
        }
        else{
            opt2 = solve(k, n-1, vetpesos, vetvalores, matriz);
        }
        matriz[n][k] = max(opt1, opt2);
        return matriz[n][k];
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}