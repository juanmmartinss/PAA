/*
Nome: Juan Marcos Martins
Ra: 156470
Projeto e Análise de Algoritmos- Reginaldo- Integral
UNIFESP-SJC
*/
 
#include <stdio.h>
#include <stdlib.h>
 
int Programacao_dinamica(int K, int *sitios, int N, int T1menor, int T2maior, int vetor_de_memorizacao[]);
int funcao_compara(int compara1, int compara2, int K, int vetor_de_memorizacao[]);
void verifica(int T1, int T2, int K, int *sitios, int N, int vetor_de_memorizacao[]);
 
int main(){
    int N, C, T1, T2;
    int K = 0, i = 0;
 
    scanf("%d", &N);
    scanf("%d", &C);
    scanf("%d", &T1);
    scanf("%d", &T2);
 
    int sitios[N];
    int vetor_de_memorizacao[N];
    
    for (int i = 0; i < N; i++){//inicializa o vetor de memorizacao com 0
        scanf("%d", &sitios[i]);
    }
 
    while(i < N){//inicializa o vetor de memorizacao com 0
        vetor_de_memorizacao[i] = 0;
        i++;
    }
 
    verifica(T1, T2, K, sitios, N, vetor_de_memorizacao);//funcao que verifica qual o menor tempo e qual o maior tempo
 
    return 0;
}
 
int Programacao_dinamica(int K, int *sitios, int N, int T1menor, int T2maior, int vetor_de_memorizacao[]){//funcao recursiva que calcula o menor tempo
    int compara1, compara2;
    int numero_de_vezes_proxima, posicao_anterior;
 
    if(K == N){//caso base
        return 0;
    }
    else if(K == N-1){//caso base
        return vetor_de_memorizacao[K] = T1menor;
    }
    else if(vetor_de_memorizacao[K] != 0){//caso base
        return vetor_de_memorizacao[K];
    }

    numero_de_vezes_proxima = 0;//variavel que conta quantas vezes o for vai rodar
    posicao_anterior = K;//variavel que guarda a posicao anterior
    
    for(K = posicao_anterior; K < N; K++){//for que conta quantas vezes o for vai rodar
        if(sitios[K] - sitios[posicao_anterior] <= T1menor){//condicao para o for rodar
            numero_de_vezes_proxima++;
        }
        else{//caso a condicao nao seja atendida, o for para
            break;
        }
    }
    if(K == N){//caso base
        compara1 = T1menor;
    }
    else{//caso recursivo
        compara1 = T1menor + Programacao_dinamica(K, sitios, N, T1menor, T2maior, vetor_de_memorizacao);
    }
 
    K = K - numero_de_vezes_proxima;//volta a posicao anterior
 
    numero_de_vezes_proxima = 0;
    posicao_anterior = K;
 
    for(K = posicao_anterior; K < N; K++){//for que conta quantas vezes o for vai rodar
        if(sitios[K] - sitios[posicao_anterior] <= T2maior){//condicao para o for rodar
            numero_de_vezes_proxima++;
        }
        else{//caso a condicao nao seja atendida, o for para
            break;
        }
    }
    
    if(K == N){//caso base
        compara2 = T2maior;
    }
    else{//caso recursivo
 
        compara2 = T2maior + Programacao_dinamica(K, sitios, N, T1menor, T2maior, vetor_de_memorizacao);//funcao recursiva
    }
    K = K - numero_de_vezes_proxima;//volta a posicao anterior
 
    int retorna = funcao_compara(compara1, compara2, K, vetor_de_memorizacao);//funcao que compara os dois valores e retorna o menor
 
    return retorna;
}
 
int funcao_compara(int compara1, int compara2, int K, int vetor_de_memorizacao[]){//funcao que compara os dois valores e retorna o menor
    if(compara1 <= compara2){//condicao para retornar o menor valor
        vetor_de_memorizacao[K] = compara1;
        return compara1;
    }
    else{//condicao para retornar o menor valor
        vetor_de_memorizacao[K] = compara2;
        return compara2;
    }
}
 
void verifica(int T1, int T2, int K, int *sitios, int N, int vetor_de_memorizacao[]){//funcao que verifica qual o menor tempo e qual o maior tempo
    int T1menor, T2maior;
    if(T1 < T2){//condicao para verificar qual o menor tempo e qual o maior tempo
        T1menor = T1;
        T2maior = T2;
    }
    else if(T1 > T2){//condicao para verificar qual o menor tempo e qual o maior tempo
        T1menor = T2;
        T2maior = T1;
    }
 
    Programacao_dinamica(K, sitios, N, T1menor, T2maior, vetor_de_memorizacao);//funcao recursiva
    
    printf("%d", vetor_de_memorizacao[0]);
}