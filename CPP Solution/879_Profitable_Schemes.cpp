// Link: https://leetcode.com/problems/profitable-schemes/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int profitableSchemes(int G, int P, vector<int> &group, vector<int> &profit)
    {
        int n = group.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(P + 1, vector<int>(G + 1, 0)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int g = group[i - 1];
            int p = profit[i - 1];
            for (int j = 0; j <= P; j++)
            {
                for (int k = 0; k <= G; k++)
                {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (k >= g)
                    {
                        dp[i][j][k] += dp[i - 1][max(0, j - p)][k - g];
                    }
                    dp[i][j][k] %= 1000000007;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= G; i++)
        {
            ans += dp[n][P][i];
            ans %= 1000000007;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> group;
    vector<int> profit;
    int G;
    int P;

    // Output: 2
    G = 5, P = 3, group = {2, 2}, profit = {2, 3};
    cout << sol.profitableSchemes(G, P, group, profit) << endl;

    // Output: 7
    G = 10, P = 5, group = {2, 3, 5}, profit = {6, 7, 8};
    cout << sol.profitableSchemes(G, P, group, profit) << endl;

    return 0;
}
