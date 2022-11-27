// Link: https://leetcode.com/problems/search-insert-position/

#include <stdio.h>


int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

int main() {
    int nums[] = {1, 3, 5, 6};
    int target = 5;
    int result = searchInsert(nums, sizeof(nums) / sizeof(int), target);
    printf("%d", result);
    return 0;
}