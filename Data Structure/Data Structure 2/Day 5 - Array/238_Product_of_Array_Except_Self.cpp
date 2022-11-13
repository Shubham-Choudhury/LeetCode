// Link: https://leetcode.com/problems/product-of-array-except-self/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int left = 1;
        int right = 1;
        for(int i = 0; i < n; i++) {
            ans[i] *= left;
            left *= nums[i];
            ans[n - i - 1] *= right;
            right *= nums[n - i - 1];
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    vector<int> res = s.productExceptSelf(nums);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}