// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);
    *returnSize = 2;
    result[0] = -1;
    result[1] = -1;
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            int i = mid;
            while (i >= 0 && nums[i] == target) {
                i--;
            }
            result[0] = i + 1;
            i = mid;
            while (i < numsSize && nums[i] == target) {
                i++;
            }
            result[1] = i - 1;
            return result;
        }
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return result;
}

int main() {
    int nums[] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int returnSize;
    int* result = searchRange(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    printf("%d %d", result[0], result[1]);
    return 0;
}