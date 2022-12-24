// Link: https://leetcode.com/problems/largest-plus-sign/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>> &mines)
    {
        vector<vector<int>> grid(N, vector<int>(N, 1));
        for (auto &mine : mines)
            grid[mine[0]][mine[1]] = 0;
        vector<vector<int>> left(N, vector<int>(N, 0));
        vector<vector<int>> right(N, vector<int>(N, 0));
        vector<vector<int>> up(N, vector<int>(N, 0));
        vector<vector<int>> down(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 1)
                {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                    up[i][j] = (i == 0 ? 0 : up[i - 1][j]) + 1;
                }
            }
        }
        for (int i = N - 1; i >= 0; i--)
        {
            for (int j = N - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    right[i][j] = (j == N - 1 ? 0 : right[i][j + 1]) + 1;
                    down[i][j] = (i == N - 1 ? 0 : down[i + 1][j]) + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ans = max(ans, min({left[i][j], right[i][j], up[i][j], down[i][j]}));
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> mines;
    int n;
    int ans;

    // Output: 2
    mines = {{4, 2}};
    n = 5;
    ans = sol.orderOfLargestPlusSign(n, mines);
    cout << ans << endl;

    // Output: 1
    mines = {};
    n = 2;
    ans = sol.orderOfLargestPlusSign(n, mines);
    cout << ans << endl;

    // Output: 0
    mines = {{0, 0}};
    n = 1;
    ans = sol.orderOfLargestPlusSign(n, mines);
    cout << ans << endl;

    return 0;
}
