// Link: https://leetcode.com/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        if(nums.size() == 1) {
            return nums[0];
        }
        if(nums.size() == 2) {
            return max(nums[0], nums[1]);
        }
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int res = dp[n - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for(int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        res = max(res, dp[n - 1]);
        return res;
    }
};

int main() {
    vector<int> nums = {2, 3, 2};
    Solution s;
    cout << s.rob(nums) << endl;
    return 0;
}