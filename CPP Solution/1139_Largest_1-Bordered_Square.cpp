// Link: https://leetcode.com/problems/largest-1-bordered-square/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largest1BorderedSquare(vector<vector<int>> &grid, int res = 0)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n)), col(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j])
                    row[i][j] = (j ? row[i][j - 1] : 0) + 1;
        for (int j = 0; j < n; ++j)
            for (int i = 0; i < m; ++i)
                if (grid[i][j])
                    col[i][j] = (i ? col[i - 1][j] : 0) + 1;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = min(row[i][j], col[i][j]); k > res; --k)
                    if (row[i - k + 1][j] >= k && col[i][j - k + 1] >= k)
                        res = k;
        return res * res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    cout << s.largest1BorderedSquare(grid);
    return 0;
}
