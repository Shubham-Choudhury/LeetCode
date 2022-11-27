// Link: https://leetcode.com/problems/3sum-closest/

#include <stdio.h>
#include <stdlib.h>


int cmpfunc(const void* a, const void* b){
    return *(int*)a - *(int*)b ;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int n = numsSize;
    qsort(nums, n, sizeof(int), cmpfunc);
    int ans = nums[0] + nums[1] + nums[n-1];
    if(ans == target)
        return ans;
    int l, r, sum;
    for(int i = 0; i < n-2; i++){
        l = i+1;
        r = n-1;
        while(l < r){
            sum = nums[i] + nums[l] + nums[r];
            if(abs(sum - target) < abs(ans - target))
                ans = sum;
            if(sum == target)
                break;
            if(sum > target)
                r--;
            else
                l++;
        }
    }

    return ans;
}

int main() {
    int nums[] = {-1, 2, 1, -4};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 1;
    int result = threeSumClosest(nums, numsSize, target);
    printf("%d", result);
    return 0;
}
