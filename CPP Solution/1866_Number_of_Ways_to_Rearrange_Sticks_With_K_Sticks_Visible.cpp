// Link: https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rearrangeSticks(int n, int k)
    {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] + (long)dp[i - 1][j] * (i - 1)) % mod;
            }
        }
        return dp[n][k];
    }
};

int main()
{
    Solution s;
    cout << s.rearrangeSticks(3, 2) << endl;
    cout << s.rearrangeSticks(5, 5) << endl;
    cout << s.rearrangeSticks(20, 11) << endl;
    return 0;
}
