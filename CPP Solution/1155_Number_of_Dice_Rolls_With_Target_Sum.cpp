// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRollsToTarget(int d, int f, int target)
    {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= target; j++)
            {
                for (int k = 1; k <= f && k <= j; k++)
                {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
                }
            }
        }
        return dp[d][target];
    }
};

int main()
{
    Solution s;
    int d = 30, f = 30, target = 500;
    cout << s.numRollsToTarget(d, f, target);
    return 0;
}
