// Link: https://leetcode.com/problems/new-21-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double new21Game(int N, int K, int W)
    {
        if (K == 0)
            return 1;
        vector<double> dp(K + W, 0);
        for (size_t i = K; i <= N && i < K + W; i++)
        {
            dp[i] = 1;
        }
        dp[K - 1] = 1.0 * min(N - K + 1, W) / W;
        for (int i = K - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] - (dp[i + W + 1] - dp[i + 1]) / W;
        }
        return dp[0];
    }
};

int main()
{
    Solution sol;
    cout << sol.new21Game(10, 1, 10) << endl;
    cout << sol.new21Game(6, 1, 10) << endl;
    cout << sol.new21Game(21, 17, 10) << endl;
    return 0;
}