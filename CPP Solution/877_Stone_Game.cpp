// Link: https://leetcode.com/problems/stone-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = piles[i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;
    }
};

int main()
{
    Solution s;
    vector<int> piles = {5, 3, 4, 5};
    cout << s.stoneGame(piles) << endl;
    return 0;
}
