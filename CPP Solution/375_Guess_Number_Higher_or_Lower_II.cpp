// Link: https://leetcode.com/problems/guess-number-higher-or-lower-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int dfs(int left, int right)
    {
        if (left == right)
            return 0;
        if (dp[left][right])
            return dp[left][right];
        dp[left][right] = INT_MAX / 2;
        for (int i = left; i <= right; i++)
        {
            if (i == left)
            {
                dp[left][right] = min(dp[left][right], i + dfs(i + 1, right));
            }
            else if (i == right)
            {
                dp[left][right] = min(dp[left][right], i + dfs(left, i - 1));
            }
            else
            {
                dp[left][right] = min(dp[left][right], i + max(dfs(left, i - 1), dfs(i + 1, right)));
            }
        }

        return dp[left][right];
    }
    int getMoneyAmount(int n)
    {
        dp.assign(n + 1, vector<int>(n + 1));
        dfs(1, n);
        return dp[1][n];
    }
};

int main()
{
    Solution s;
    cout << s.getMoneyAmount(10) << endl;
    return 0;
}
