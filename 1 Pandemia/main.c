/*
Nome: Juan Marcos Martins
Ra: 156470
Projeto e análise de algoritmos- Reginaldo- Integral
*/
 
#include <stdio.h>
#include <stdlib.h>
 
int main(){
    int d,n; //d distancia entre os pontos, n numero de posicoes apresentadas no relatorio;
    int x,y,i; //(x e y coordenadas e i eh a quantidade de usuarios);
 
    scanf("%d",&d);
    scanf("%d",&n);
 
    int vet[n]; //Vetor para armazenar as posicoes dos usuarios;
    int vetx[n]; //Vetor para armazenar as posicoes dos usuarios em x;
    int vety[n]; //Vetor para armazenar as posicoes dos usuarios em y;
 
    for(int j = 0; j < n; j++){
        scanf("%d",&x);
        scanf("%d",&y);
        scanf("%d",&i);
 
        vet[j] = i; //Colocando as posicoes dos usuarios no vetor;
        vetx[j] = x; //Colocando as posicoes dos usuarios em x no vetor;
        vety[j] = y; //Colocando as posicoes dos usuarios em y no vetor;
 
    }
    //teste
    for(int j = 0; j < n; j++){
        printf("(x, y)= %d, %d \n", vetx[j], vety[j]);
    }
    //printf("saiu aqui");
    int total = 0;
    int guardax;
    int guarday;
 
    for(int k = 0; k < n; k++){
        for(int j = k + 1; j < n; j++){
            if(vetx[j] >= vetx[k] && vety[j] >= vety[k]){
                if(vetx[j] - d <= vetx[k] + d && vety[j] - d <= vety[k] + d){
                    printf("entra na primeira comparacao");
                    /*
                        10
                        2
                        40 40 10
                        60 60 20
                    */
                    if(total < vet[k] + vet[j]){
                        printf("entra no if da primeira");
                        total = vet[k] + vet[j];
                        guardax = vetx[j] - d;
                        guarday = vety[j] - d;
 
                    }
                }
            }
            if(vetx[j] <= vetx[k] && vety[j] <= vety[k]){
                if(vetx[j] + d >= vetx[k] - d && vety[j] + d >= vety[k] - d){
                    printf("entra na segunda comparacao");
                    if(total < vet[k] + vet[j]){
                        printf("entra no if da segunda");
                        total = vet[k] + vet[j];
                        guardax = vetx[k] - d;
                        guarday = vety[k] - d;
                    }
                }
            }
            if(vetx[j] >= vetx[k] && vety[j] <= vety[k]){
                if(vetx[j] - d <= vetx[k] + d && vety[j] + d >= vety[k] - d){
                    printf("entra na terceira comparacao");
                    if(total < vet[k] + vet[j]){
                        total = vet[k] + vet[j];
                        guardax = vetx[j] - d;
                        guarday = vety[k] - d;
                    }
                }
            }
            if(vetx[j] <= vetx[k] && vety[j] >= vety[k]){
                if(vetx[j] + d >= vetx[k] - d && vety[j] - d <= vety[k] + d){
                    printf("entra na quarta comparacao");
                    if(total < vet[k] + vet[j]){
                        total = vet[k] + vet[j];
                        guardax = vetx[k] - d;
                        guarday = vety[j] - d;
                    }
                }
            }
        }
    }
    for(int j = 0; j < n; j++){
        if(total < vet[j]){
            total = vet[j];
            guardax = vetx[j];
            guarday = vety[j];
        }
        else if(total == vet[j]){
            if(guardax > vetx[j]){
                guardax = vetx[j]-d;
                guarday = vety[j]-d;
            }
            else if(guardax == vetx[j]){
                if(guarday > vety[j]){
                    guarday = vety[j]-d;
                }
            }

 
        }
    }
 
    printf("%d %d %d", guardax, guarday, total);
 
 
    return 0;
}