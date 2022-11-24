// Link: https://leetcode.com/problems/maximum-product-subarray/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int temp = maxProduct;
            maxProduct = max(max(maxProduct * nums[i], minProduct * nums[i]), nums[i]);
            minProduct = min(min(temp * nums[i], minProduct * nums[i]), nums[i]);
            result = max(result, maxProduct);
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 3, -2, 4};
    Solution obj;
    cout << obj.maxProduct(nums);
    return 0;
}