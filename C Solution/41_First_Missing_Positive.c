// Link: https://leetcode.com/problems/first-missing-positive/

#include <stdio.h>
#include <stdlib.h>


int firstMissingPositive(int* nums, int numsSize){
    int i = 0;
    while (i < numsSize){
        if (nums[i] > 0 && nums[i] <= numsSize && nums[i] != i+1 && nums[i] != nums[nums[i]-1]){
            int temp = nums[i];
            nums[i] = nums[temp-1];
            nums[temp-1] = temp;
        } else {
            i++;
        }
    }
    for (i = 0 ; i < numsSize ; i++){
        if (nums[i] != i+1){
            return i+1;
        }
    }
    return numsSize+1;
}

int main() {
    int nums[] = {3,4,-1,1};
    int max = firstMissingPositive(nums, 4);
    printf("%d", max);
    return 0;
}