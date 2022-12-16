// Link: https://leetcode.com/problems/cat-and-mouse/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    int dp[101][101][501];

    int solve(int m, int c, int moves, int n, vector<vector<int>> &g)
    {

        if (moves > 5 * n)
        {
            return 0;
        }

        if (m == c)
        {
            return dp[m][c][moves] = 2;
        }

        if (m == 0)
        {
            return dp[m][c][moves] = 1;
        }

        if (dp[m][c][moves] != -1)
        {
            return dp[m][c][moves];
        }

        if (moves % 2 == 0)
        {
            bool isDraw = false;

            for (auto &x : g[m])
            {
                int ans = solve(x, c, moves + 1, n, g);
                if (ans == 1)
                {
                    return dp[m][c][moves] = 1;
                }
                if (ans == 0)
                {
                    isDraw = true;
                }
            }

            if (isDraw)
            {
                return dp[m][c][moves] = 0;
            }
            return dp[m][c][moves] = 2;
        }
        else
        {

            bool isDraw = false;

            for (auto &x : g[c])
            {
                if (x == 0)
                {
                    continue;
                }
                int ans = solve(m, x, moves + 1, n, g);
                if (ans == 2)
                {
                    return dp[m][c][moves] = 2;
                }
                if (ans == 0)
                {
                    isDraw = true;
                }
            }
            if (isDraw)
            {
                return dp[m][c][moves] = 0;
            }
            return dp[m][c][moves] = 1;
        }
    }

    int catMouseGame(vector<vector<int>> &g)
    {
        int n = g.size();
        memset(dp, -1, sizeof(dp));
        return solve(1, 2, 0, n, g);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> graph;

    // Output: 0
    graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    cout << sol.catMouseGame(graph) << endl;

    // Output: 1
    graph = {{1, 3}, {0}, {3}, {0, 2}};
    cout << sol.catMouseGame(graph) << endl;

    // Output: 1
    graph = {{1, 2, 3}, {0}, {0}, {0}};
    cout << sol.catMouseGame(graph) << endl;

    // Output: 2
    graph = {{2, 3, 4}, {3, 4}, {0, 4}, {0, 1}, {0, 1, 2}};
    cout << sol.catMouseGame(graph) << endl;

    // Output: 1
    graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
    cout << sol.catMouseGame(graph) << endl;

    return 0;
}
