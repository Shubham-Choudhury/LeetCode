// Link: https://leetcode.com/problems/soup-servings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double soupServings(int N)
    {
        if (N > 4800)
            return 1.0;
        vector<vector<double>> dp(200, vector<double>(200, -1));
        return helper((N + 24) / 25, (N + 24) / 25, dp);
    }

    double helper(int a, int b, vector<vector<double>> &dp)
    {
        if (a <= 0 && b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (dp[a][b] > -0.5)
            return dp[a][b];
        dp[a][b] = 0.25 * (helper(a - 4, b, dp) + helper(a - 3, b - 1, dp) + helper(a - 2, b - 2, dp) + helper(a - 1, b - 3, dp));
        return dp[a][b];
    }
};

int main()
{
    Solution sol;
    cout << sol.soupServings(50) << endl;
    return 0;
}
