// Link: https://leetcode.com/problems/coloring-a-border/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &g, int r, int c, int cl)
    {
        if (r < 0 || c < 0 || r >= g.size() || c >= g[r].size() || g[r][c] != cl)
            return;
        g[r][c] = -cl;
        dfs(g, r - 1, c, cl), dfs(g, r + 1, c, cl), dfs(g, r, c - 1, cl), dfs(g, r, c + 1, cl);
        if (r > 0 && r < g.size() - 1 && c > 0 && c < g[r].size() - 1 && cl == abs(g[r - 1][c]) &&
            cl == abs(g[r + 1][c]) && cl == abs(g[r][c - 1]) && cl == abs(g[r][c + 1]))
            g[r][c] = cl;
    }
    vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
    {
        dfs(grid, r0, c0, grid[r0][c0]);
        for (auto i = 0; i < grid.size(); ++i)
            for (auto j = 0; j < grid[i].size(); ++j)
                grid[i][j] = grid[i][j] < 0 ? color : grid[i][j];
        return grid;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 1}, {1, 2}};
    int r0 = 0, c0 = 0, color = 3;
    vector<vector<int>> res = sol.colorBorder(grid, r0, c0, color);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
