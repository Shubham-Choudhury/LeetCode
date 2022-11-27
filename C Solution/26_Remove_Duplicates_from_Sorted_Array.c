// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if(numsSize == 0)
        return 0;
    int i = 0, j = 1;
    while(j < numsSize){
        if(nums[i] != nums[j]){
            i++;
            nums[i] = nums[j];
        }
        j++;
    }
    return i + 1;
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = 10;
    int result = removeDuplicates(nums, numsSize);
    printf("%d", result);
    return 0;

}