/*
Nome: Juan Marcos Martins
Ra: 156470
Projeto e Análise de Algoritmos- Reginaldo- Integral
UNIFESP-SJC
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
//Declaracao das funcoes utilizadas
 
int pegapotenciamaisproxima(int n);
 
int main(){
 
    int n, cont = 0;//n é o número de entrada, cont é o contador de operações
    
    scanf("%d", &n);
 
    while(n > 0){//Enquanto n for maior que 0
        n = abs(n - pegapotenciamaisproxima(n));//n recebe o valor absoluto da diferença entre n e a potência de 2 mais próxima de n
        cont++;
    }
    printf("%d", cont);
 
    return 0;
}
 
int pegapotenciamaisproxima(int n){//Função que retorna a potência de 2 mais próxima de n
    
    float guarda3, guarda1, guarda2;
    guarda3 = log2(n);//guarda3 recebe o logaritmo de n na base 2
    guarda1 = floor(guarda3);//guarda1 recebe o piso de guarda3
    guarda2 = ceil(guarda3);//guarda2 recebe o teto de guarda3
    
    if(guarda2 - guarda3 < guarda3 - guarda1){//Se a diferença entre guarda2 e guarda3 for menor que a diferença entre guarda3 e guarda1
        return pow(2,(int)guarda2);//Retorna 2 elevado a guarda2
    }
    else{
        return pow(2,(int)guarda1);//Retorna 2 elevado a guarda1
    }
}