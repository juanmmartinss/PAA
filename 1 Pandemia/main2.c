/*
Nome: Juan Marcos Martins
Ra: 156470
Projeto e Análise de Algoritmos- Reginaldo- Integral
*/
#include <stdio.h>
#include <stdlib.h>
#define max 1024
 
int verificamin(int x, int d); //funcao para verificar se o valor minimo eh menor que 0
int verificamax(int x, int d); //funcao para verificar se o valor maximo eh maior que 1024
 
int main(){
    int matriz[max + 1][max + 1] = {0}; //matriz para armazenar os pontos
 
    int d, n; //d distancia entre os pontos, n numero de posicoes apresentadas no relatorio;
    int x, y, i; //(x e y coordenadas e i eh a quantidade de usuarios);
    int varx = 0, vary = 0, numpes = 0;
 
    scanf("%d", &d);
    scanf("%d", &n);
 
    for(int j = 0; j < n; j++){ //leitura dos pontos
        scanf("%d", &x);
        scanf("%d", &y);
        scanf("%d", &i);
 
        for(int k = verificamin(x,d); k <= verificamax(x,d); k++){ //verificando os pontos em x
            for(int l = verificamin(y,d); l <= verificamax(y,d); l++){ //verificando os pontos em y
                matriz[k][l] += i;
 
                if(matriz[k][l] > numpes){ //verificando qual ponto tem o maior numero de pessoas
                    varx = k;
                    vary = l;
                    numpes = matriz[k][l];
                }
                else if(matriz[k][l] == numpes){ //verificando qual ponto tem o menor x
                    if(k < varx){ //verificando qual ponto tem o menor x
                        varx = k;
                        vary = l;
                    }
                }
            }
        }
    }
 
    printf("%d %d %d", varx, vary, numpes); //imprimindo o ponto com maior numero de pessoas
 
    return 0;
}
 
int verificamin(int x, int d){ //funcao para verificar se o valor minimo eh menor que 0
    if(x - d >= 1){
        return x - d; //verificando se o valor minimo eh menor que 0
    }
    return 1;
}
int verificamax(int x, int d){ //funcao para verificar se o valor maximo eh maior que 1024
    if(x + d <= max){
        return x + d; //verificando se o valor maximo eh maior que 1024
    }
    return max;
}