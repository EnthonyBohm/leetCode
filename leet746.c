#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize);
int encontraMenor(int* vetor, int tamVetor, int posAtual);

int main(){

    int teste1[3] = {10, 15, 20};
    minCostClimbingStairs(teste1, 3);

    return 0;
}


int minCostClimbingStairs(int* cost, int costSize){
    int i, j, finalValue = 0, tempValue1, tempValue2;
    
    /*
    Testar o primeiro valor, ja somando ele, preciso de variável nova, de soma_provisória
    Testar esse valor com o primeiro e o segundo e ver qual deles é o menor ou, se o 
    Se o próxima valor for
    */
    
    for(i = 0, j=i+1; i < costSize;){
        tempValue1= 0;
        tempValue2 = 0;
        
        if(i == 0){
            tempValue1 += cost[i];
            tempValue2 += cost[j];
            i = encontraMenor(cost, costSize, i);
            tempValue1 += cost[i];
            j = encontraMenor(cost, costSize, j);
            tempValue2 += cost[j];

            printf("1:%d & 2:%d", tempValue1, tempValue2);
        }
        return finalValue;
    }
    

int encontraMenor(int* vetor, int tamVetor, int posAtual){
    int first, second;
    
    if((posAtual +1 )< tamVetor){
        return posAtual +1;
    }
    if((posAtual +2) < tamVetor ){
        return posAtual +2;
    }

    first = vetor[posAtual+1];
    second = vetor[posAtual+2];

    if(first < second){
        return 1;
    }
    return 2; 
}