// Link: https://leetcode.com/problems/shortest-path-to-get-all-keys/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

int e[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

class Solution
{
public:
    int m;
    int n;
    int chars;
    vector<pair<int, int>> pos;
    int findPath(vector<string> &grid, string &order, int tar, int x, int y)
    {

        if (tar == order.length())
            return 0;
        int x_ = pos[order[tar] - 'a'].first;
        int y_ = pos[order[tar] - 'a'].second;
        vector<vector<int>> d(m, vector<int>(n, INT_MAX));
        d[x][y] = 0;
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while (!q.empty())
        {

            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            if (grid[cx][cy] == order[tar])
                break;
            for (int k = 0; k < 4; k++)
            {
                int tx = cx + e[k][0];
                int ty = cy + e[k][1];
                if (tx >= 0 && ty >= 0 && tx < m && ty < n)
                {
                    char c = grid[tx][ty];
                    if (c == '#')
                        continue;
                    if (d[tx][ty] != INT_MAX)
                        continue;
                    if (c >= 'A' && c <= 'F')
                    {
                        char c_ = c - 'A' + 'a';
                        bool flag = false;
                        for (int i = 0; i < tar; i++)
                        {
                            if (c_ == order[i])
                                flag = true;
                        }
                        if (!flag)
                            continue;
                    }
                    d[tx][ty] = 1 + d[cx][cy];
                    q.push(make_pair(tx, ty));
                }
            }
        }
        if (d[x_][y_] == INT_MAX)
            return -1;
        int dn = findPath(grid, order, tar + 1, x_, y_);
        if (dn == -1)
            return -1;
        return d[x_][y_] + dn;
    }

    int shortestPathAllKeys(vector<string> &grid)
    {

        m = grid.size();
        n = grid[0].size();
        string order = "abcdef";
        int result = INT_MAX;
        int x;
        int y;
        for (int i = 0; i < 6; i++)
        {
            pos.push_back(make_pair(-1, -1));
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                {
                    x = i;
                    y = j;
                }
                if (grid[i][j] >= 'a' && grid[i][j] <= 'f')
                {
                    pos[grid[i][j] - 'a'].first = i;
                    pos[grid[i][j] - 'a'].second = j;
                }
            }
        }
        chars = 0;
        for (int i = 0; i < 6; i++)
            if (pos[i].first >= 0)
                chars++;
        order = order.substr(0, chars);
        string order_ = order;

        for (int i = 0; i < 720; i++)
        {

            int d = findPath(grid, order, 0, x, y);
            if (d != -1)
                result = min(result, d);
            next_permutation(order.begin(), order.end());
            if (order_ == order)
                break;
        }
        return result == INT_MAX ? -1 : result;
    }
};

int main()
{
    Solution sol;
    vector<string> grid;

    // Output: 8
    grid = {"@.a.#", "###.#", "b.A.B"};
    cout << sol.shortestPathAllKeys(grid) << endl;

    // Output: 11
    grid = {"@..aA", "..B#.", "....b"};
    cout << sol.shortestPathAllKeys(grid) << endl;

    return 0;
}
