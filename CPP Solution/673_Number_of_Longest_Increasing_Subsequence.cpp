// Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxLen = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                res += count[i];
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    cout << sol.findNumberOfLIS(nums) << endl;
    return 0;
}