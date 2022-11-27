// Link: https://leetcode.com/problems/remove-element/

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val){
    int i = 0, j = 0;
    while(i < numsSize){
        if(nums[i] != val){
            nums[j] = nums[i];
            j++;
        }
        i++;
    }
    return j;
}

int main() {
    int nums[] = {3, 2, 2, 3};
    int numsSize = 4;
    int val = 3;
    int len = removeElement(nums, numsSize, val);
    for(int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    return 0;
}