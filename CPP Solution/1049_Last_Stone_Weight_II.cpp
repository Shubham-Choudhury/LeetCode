// Link: https://leetcode.com/problems/last-stone-weight-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (auto &stone : stones)
            sum += stone;
        int n = stones.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(sum / 2 + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if (j >= stones[i - 1])
                    dp[i][j] = dp[i][j] || dp[i - 1][j - stones[i - 1]];
            }
        }
        for (int j = sum / 2; j >= 0; j--)
            if (dp[n][j])
                return sum - 2 * j;
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> stones = {2, 7, 4, 1, 8, 1};
    cout << sol.lastStoneWeightII(stones) << endl;
    return 0;
}

