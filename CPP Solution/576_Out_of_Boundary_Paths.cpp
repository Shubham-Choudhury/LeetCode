// Link: https://leetcode.com/problems/out-of-boundary-paths/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPaths(int m, int n, int N, int i, int j)
    {
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(m, vector<int>(n, 0)));
        int mod = 1e9 + 7;
        for (int k = 1; k <= N; ++k)
        {
            for (int x = 0; x < m; ++x)
            {
                for (int y = 0; y < n; ++y)
                {
                    long long up = x == 0 ? 1 : dp[k - 1][x - 1][y];
                    long long down = x == m - 1 ? 1 : dp[k - 1][x + 1][y];
                    long long left = y == 0 ? 1 : dp[k - 1][x][y - 1];
                    long long right = y == n - 1 ? 1 : dp[k - 1][x][y + 1];
                    dp[k][x][y] = (up + down + left + right) % mod;
                }
            }
        }
        return dp[N][i][j];
    }
};

int main(void)
{
    Solution sol;
    cout << sol.findPaths(2, 2, 2, 0, 0) << endl;
    cout << sol.findPaths(1, 3, 3, 0, 1) << endl;
    return 0;
}
