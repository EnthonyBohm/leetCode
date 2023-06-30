#include <stdio.h>

int minCostClimbingStairs(int* cost, int costSize);
int encontraMenor(int* vetor, int tamVetor, int posAtual);

int main(){
    int valorFinal;
    // int teste1[3] = {10, 15, 20};
    // minCostClimbingStairs(teste1, 3);

    // int teste1[10] = {1,100,1,1,1,100,1,1,100,1};
    // minCostClimbingStairs(teste1, 10);

    int teste1[4] = {0, 1, 2, 2};
    valorFinal = minCostClimbingStairs(teste1, 4);

    printf("\n Valor Final: %d", valorFinal);
    return 0;
}


int minCostClimbingStairs(int* cost, int costSize){
    int finalValue = 0, tempValue1, tempValue2, funcResult, funcResult2;
    int i, j;
    
    for(i = 0, j= 1; i < costSize;){
        if(i == 0){
            tempValue1 = cost[i];
            tempValue2 = cost[j];

            funcResult = encontraMenor(cost, costSize, i);
            funcResult2 = encontraMenor(cost, costSize, j);
            
            if(funcResult == -1){
                i+=1;
                finalValue = tempValue1;
                break;
            }
            else
                tempValue1 += cost[funcResult];
                
                
            if(funcResult2 == -1){
                i += 2;
                finalValue = tempValue2;
                break;
            }
            else
                tempValue2 += cost[funcResult2];
                

            if(tempValue1 < tempValue2){
                i = funcResult;
                finalValue += cost[0];
            }
            else{
                i = funcResult2;
                finalValue += cost[1];
            }

        }
        else{
            finalValue += cost[i];
            funcResult = encontraMenor(cost, costSize, i);
            if(funcResult == -1)
                break;
            i += funcResult;
        }
    }
        return finalValue;
    }
    

int encontraMenor(int* vetor, int tamVetor, int posAtual){
    int first, second;
    
    if((posAtual +1 )>= tamVetor){
        return -1;
    }
    if((posAtual +2) >= tamVetor ){
        return -1;
    }

    first = vetor[posAtual+1];
    second = vetor[posAtual+2];

    if(first < second){
        return 1;
    }
    return 2; 
}