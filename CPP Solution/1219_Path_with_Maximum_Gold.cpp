// Link: https://leetcode.com/problems/path-with-maximum-gold/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != 0)
                    res = max(res, dfs(grid, i, j));
            }
        }
        return res;
    }

    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
            return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        int res = 0;
        res = max(res, dfs(grid, i + 1, j));
        res = max(res, dfs(grid, i - 1, j));
        res = max(res, dfs(grid, i, j + 1));
        res = max(res, dfs(grid, i, j - 1));
        grid[i][j] = temp;
        return res + temp;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid1 = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    cout << s.getMaximumGold(grid1);
    return 0;
}

