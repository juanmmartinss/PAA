/*
Problema 5
Sítios e antenas

Tempo limite: 0,5s(C/C++), 2s (Java/Python 2/Python 3)

A cobertura por antenas para serviços de telecomunicação em zona rural geralmente é um
grande desafio pelo número reduzido do público atingido e o alto valor a ser investido em
infraestrutura. Geralmente, as propriedades em zonas rurais estão localizadas ao longo de uma
estrada, então podemos considerar a cobertura de uma dada antena em termos do comprimento
da parte da estrada que essa antena consegue cobrir e a localização de uma residência da
propriedade rural pode ser dada pela distância do início da estrada até um dado ponto da estrada
em que essa propriedade se localiza.
Dados 2 tipos diferentes de antenas disponíveis para instalação, cada tipo possui a capacidade
de cobrir um dado comprimento de estrada. Além disso, o custo de cada antena é proporcional
ao alcance de sua cobertura. Ou seja, considere que, se uma dada antena pode cobrir x metros de
estrada, então o seu custo de instalação é R$ x. Considerando que inicialmente nenhuma das
propriedades está coberta pelo sinal, você deve determinar, para uma dada estrada e as
localizações de propriedades ao longo dessa estrada, a forma mais econômica de instalar antenas
para possibilitar a cobertura de todas as propriedades dessa estrada.
Entrada
Cada caso de teste consiste de duas linhas e corresponde a uma dada estrada. A primeira contém
os inteiros N (1 ≤ N ≤ 1.000), C (1 ≤ C ≤ 1.000.000), T1 e T2 (1 ≤ T1, T2 ≤ C). O inteiro N
representa o número de pontos na estrada e C o comprimento da estrada em metros. Os
comprimentos de estrada, em metros, que cada tipo de antena pode cobrir são dados por T1 e
T2.
A segunda linha da entrada contém N inteiros Pi(1 ≤ Pi ≤ C), sendo um para cada localização Pi
da estrada em que existe alguma residência em propriedade rural. Essa localização descreve a
distância do início da estrada até o ponto da estrada em que existe a residência.
Saída
Seu programa deve imprimir uma linha contendo um inteiro correspondendo ao menor custo de
instalação, em R$, que é suficiente para cobrir todas as propriedades de uma dada estrada.

Exemplo de Entrada
5 20 2 3
2 5 8 11 15
Exemplo de Saída
8
Exemplo de Entrada
4 20 12 9
1 2 3 13
Exemplo de Saída
12
*/

#include <stdio.h>
#include <stdlib.h>

int menor_custo = 1234567890;

int backtracking(int custo, int posicao_no_vetor, int *casas, int numero_de_casas, int poste_menor, int poste_maior, int memo[]);

int main()
{
    int numero_de_casas, comprimento_rua, poste_menor, poste_maior;
    scanf("%d %d %d %d", &numero_de_casas, &comprimento_rua, &poste_menor, &poste_maior);

    int *casas = (int *)malloc(numero_de_casas * sizeof(int));
    for (int i = 0; i < numero_de_casas; i++)
    {
        scanf("%d", &casas[i]);
    }

    int custo = 0;
    int posicao_no_vetor = 0;

    int memo[numero_de_casas];
    for(int i = 0; i < numero_de_casas; i++)
    {
        memo[i] = 0;
    }

    backtracking(custo, posicao_no_vetor, casas, numero_de_casas, poste_menor, poste_maior, memo);

    //printf("%d", memo[0]);

    printf("%d", memo[0]);
    printf("\nmemos %d\n", memo[1]);
    printf("\n%d\n", memo[2]);
    printf("\n%d\n", memo[3]);
    printf("\n%d\n", memo[4]);

    return 0;
}

int backtracking(int custo, int posicao_no_vetor, int *casas, int numero_de_casas, int poste_menor, int poste_maior, int memo[])
{

    if(posicao_no_vetor == numero_de_casas-1)
    {
        memo[posicao_no_vetor] = poste_menor;
        return memo[posicao_no_vetor];
    }

    if(memo[posicao_no_vetor] != 0)
    {
        return memo[posicao_no_vetor];
    }


    int aux1, aux2;
    int candidatos[2];
    candidatos[0] = poste_menor;
    candidatos[1] = poste_maior;

    custo += candidatos[0];
    int avanco = candidatos[0];
    int contador_avancos = 0;
    int posicao_anterior = posicao_no_vetor;
    while (posicao_no_vetor < numero_de_casas && casas[posicao_no_vetor] - casas[posicao_anterior] <= avanco)
    {
        posicao_no_vetor++;
        contador_avancos++;
    }
    aux1 = backtracking(custo, posicao_no_vetor, casas, numero_de_casas, poste_menor, poste_maior, memo);
    custo -= candidatos[0];
    posicao_no_vetor -= contador_avancos;

    custo += candidatos[1];
    avanco = candidatos[1];
    contador_avancos = 0;
    posicao_anterior = posicao_no_vetor;
    while (posicao_no_vetor < numero_de_casas && casas[posicao_no_vetor] - casas[posicao_anterior] <= avanco)
    {
        posicao_no_vetor++;
        contador_avancos++;
    }
    aux2 = backtracking(custo, posicao_no_vetor, casas, numero_de_casas, poste_menor, poste_maior, memo);
    custo -= candidatos[1];
    posicao_no_vetor -= contador_avancos;


    if(aux1 < aux2)
    {
        memo[posicao_no_vetor] = aux1;
        return aux1;
    }
    else
    {
        memo[posicao_no_vetor] = aux2;
        return aux2;
    }
}