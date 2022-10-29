// Link: https://leetcode.com/problems/binary-search/?envType=study-plan&id=binary-search-i

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int search(int* nums, int numsSize, int target){
    int left = 0;
    int right = numsSize - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {-1,0,3,5,9,12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    printf("%d", search(nums, numsSize, target));
    return 0;
}