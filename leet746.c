#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize);
/*
    A função próximo pulo define qual vai ser o pulo escolhido, de acordo com o fim do vetor, ou com o menor valor encontrado, retorno o pulo desejado
    Quando o pulo não for para a parte final, é escolhido o menor custo, e em seguida, o valor naquela posição do vetor muda para um novo valor, o novo custo
    Este custo retrata a distância até chegar ao final do vetor
*/
int nextJump(int* vector, int maxPosition,int currentPosition);

int main(){
    int valorFinal;
    int teste1[3] = {10, 15, 20};
    valorFinal = minCostClimbingStairs(teste1, 3);

    // int teste1[10] = {1,100,1,1,1,100,1,1,100,1};
    // valorFinal = minCostClimbingStairs(teste1, 10);

    // int teste1[4] = {0, 1, 2, 2};
    // valorFinal = minCostClimbingStairs(teste1, 4);

    printf("\n Valor Final: %d", valorFinal);
    return 0;
}


int minCostClimbingStairs(int* cost, int costSize){
    int i, funcReturn;

    for(i = (costSize-1); i >= 0; i--){
        funcReturn = nextJump(cost, costSize, i);

        if(funcReturn == -1)
            continue;
        
        cost[i] = funcReturn;
    }
    if(cost[1] < cost[0])
        return cost[1];
    else
        return cost[0];
}

int nextJump(int* vector, int maxPosition,int currentPosition){
    int first, second;

    if((currentPosition + 1) >= maxPosition)
        return -1;
    if((currentPosition + 2) >= maxPosition)
        return -1;

    first = vector[currentPosition] + vector[currentPosition + 1];
    second = vector[currentPosition] + vector[currentPosition + 2];

    if(first < second)
        return first;
    else
        return second;
}