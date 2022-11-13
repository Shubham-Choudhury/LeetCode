// Link: https://leetcode.com/problems/subarray-product-less-than-k/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int prod = 1;
        int count = 0;
        while(j < n) {
            prod *= nums[j];
            while(i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            count += j - i + 1;
            j++;
        }
        return count;
    }
};

int main(){
    Solution s;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << s.numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}