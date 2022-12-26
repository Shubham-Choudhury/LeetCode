// Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int m, n;
    int memo[1000][1000];
    int maximumScore(vector<int> &nums, vector<int> &muls)
    {
        n = nums.size();
        m = muls.size();
        memset(memo, -1, sizeof(memo));
        return dp(0, 0, nums, muls);
    }
    int dp(int l, int i, vector<int> &nums, vector<int> &muls)
    {
        if (i == m)
            return 0; // Picked enough m elements
        if (memo[l][i] != -1)
            return memo[l][i];
        int pickLeft = dp(l + 1, i + 1, nums, muls) + nums[l] * muls[i];            // Pick the left side
        int pickRight = dp(l, i + 1, nums, muls) + nums[n - (i - l) - 1] * muls[i]; // Pick the right side
        return memo[l][i] = max(pickLeft, pickRight);
    }
};

int main()
{
    Solution sol;
    vector<int> nums, multipliers;
    int ans;

    // Output: 14
    nums = {1, 2, 3}, multipliers = {3, 2, 1};
    ans = sol.maximumScore(nums, multipliers);
    cout << ans << endl;

    // Output: 102
    nums = {-5, -3, -3, -2, 7, 1}, multipliers = {-10, -5, 3, 4, 6};
    ans = sol.maximumScore(nums, multipliers);
    cout << ans << endl;

    // Output: 0
    nums = {1, -5, -3, 4, 2}, multipliers = {-2, -4, 1, -1, 3};
    ans = sol.maximumScore(nums, multipliers);
    cout << ans << endl;

    return 0;
}