// Link: https://leetcode.com/problems/queens-that-can-attack-the-king/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>> &queens, vector<int> &king)
    {
        vector<vector<int>> res;
        vector<vector<int>> grid(8, vector<int>(8, 0));
        for (int i = 0; i < queens.size(); i++)
            grid[queens[i][0]][queens[i][1]] = 1;
        int x = king[0], y = king[1];
        for (int i = x - 1; i >= 0; i--)
        {
            if (grid[i][y] == 1)
            {
                res.push_back({i, y});
                break;
            }
        }
        for (int i = x + 1; i < 8; i++)
        {
            if (grid[i][y] == 1)
            {
                res.push_back({i, y});
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--)
        {
            if (grid[x][i] == 1)
            {
                res.push_back({x, i});
                break;
            }
        }
        for (int i = y + 1; i < 8; i++)
        {
            if (grid[x][i] == 1)
            {
                res.push_back({x, i});
                break;
            }
        }
        for (int i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (grid[i][j] == 1)
            {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = x + 1, j = y + 1; i < 8 && j < 8; i++, j++)
        {
            if (grid[i][j] == 1)
            {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = x - 1, j = y + 1; i >= 0 && j < 8; i--, j++)
        {
            if (grid[i][j] == 1)
            {
                res.push_back({i, j});
                break;
            }
        }
        for (int i = x + 1, j = y - 1; i < 8 && j >= 0; i++, j--)
        {
            if (grid[i][j] == 1)
            {
                res.push_back({i, j});
                break;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> queens1 = {{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}};
    vector<int> king1 = {0, 0};
    vector<vector<int>> res1 = s.queensAttacktheKing(queens1, king1);
    for (int i = 0; i < res1.size(); i++)
        cout << res1[i][0] << " " << res1[i][1] << endl;
    return 0;
}
