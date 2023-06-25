/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize){
    int i, j, aux;
    int* returnNums;

    *returnSize = (2*n) * numsSize;
    returnNums = (int *) malloc(sizeof(int) * (2*n));
    if(!returnNums){
        printf("Impossível alocar memória para este Array");
    }
    
    for(i=0, j = 0; i<2*n; i+=2, j++){
        returnNums[i] = nums[j];
        returnNums[i+1] = nums[j+n];
    }
    
    return returnNums;
}
