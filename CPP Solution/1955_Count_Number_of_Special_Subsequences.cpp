// Link: https://leetcode.com/problems/count-number-of-special-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        vector<long long> dp(3, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                dp[0] = (dp[0] * 2 + 1) % mod;
            } else if (nums[i] == 1) {
                dp[1] = (dp[1] * 2 + dp[0]) % mod;
            } else {
                dp[2] = (dp[2] * 2 + dp[1]) % mod;
            }
        }
        return dp[2];
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0,1,2,2};
    cout << sol.countSpecialSubsequences(nums) << endl;
    return 0;
}