// Link: https://leetcode.com/problems/house-robber-ii/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        int ans = dp[n - 2];
        dp[0] = 0;
        dp[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        ans = max(ans, dp[n - 1]);
        return ans;
    }
};

int main(){
    vector<int> nums = {2,3,2};
    Solution obj;
    int ans = obj.rob(nums);
    cout << ans << endl;
    return 0;
}