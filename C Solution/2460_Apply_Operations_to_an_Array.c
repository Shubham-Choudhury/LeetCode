// Link: https://leetcode.com/problems/apply-operations-to-an-array/

#include <stdio.h>
#include <stdlib.h>

int* applyOperations(int* nums, int numsSize, int* returnSize){
    int ansIdx = 0;
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i]){
            int isTheSame = (nums[i]==nums[i+1])? 1 : 0;
            nums[ansIdx++] = isTheSame? nums[i] * 2 : nums[i];
            nums[i+1] = isTheSame? 0 : nums[i+1];
        }     
    }
    /* process the last element */
    if(nums[numsSize - 1]) 
        nums[ansIdx++] = nums[numsSize - 1];
    /* fill zero */
    for(int i = ansIdx; i < numsSize; i++)
        nums[i] = 0;
    *returnSize = numsSize;
    return nums;
}

int main()
{
    int nums[] = {1, 2, 2, 1, 1, 0};
    int numSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    int *result = applyOperations(nums, numSize, &returnSize);
    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }
    return 0;
}