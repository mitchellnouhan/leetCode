int findDuplicate(int* nums, int numsSize){
    int* indexNums = malloc(sizeof(int) * (numsSize - 1));
    for (int i = 0; i < numsSize - 1; i++){
        indexNums[i] = 0;
    }
    for (int i = 0; i < numsSize; i++){
        if (indexNums[nums[i] - 1] == 1){
            return nums[i];
        }
        else{
            indexNums[nums[i] - 1] = 1;
        }
    }
    free(indexNums);
    return -1;
}