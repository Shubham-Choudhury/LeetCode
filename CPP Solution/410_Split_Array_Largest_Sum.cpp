// Link: https://leetcode.com/problems/split-array-largest-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    Solution sol;
    vector<int> nums;
    int m;

    // Output: 18
    nums = {7, 2, 5, 10, 8}, m = 2;
    cout << sol.splitArray(nums, m) << endl;

    // Output: 6
    nums = {1, 4, 4}, m = 3;
    cout << sol.splitArray(nums, m) << endl;

    // Output: 15
    nums = {1, 2147483647}, m = 2;
    cout << sol.splitArray(nums, m) << endl;

    return 0;
}