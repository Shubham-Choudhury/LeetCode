// Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        // if(grid[grid.size()-1][grid[0].size()-1]!=6 && grid[grid.size()-1][grid[0].size()-1]!=1){return false;}
        int p1 = 0, p2 = 0;
        vector<vector<int>> v(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> v1(grid.size(), vector<int>(grid[0].size(), 1));
        queue<pair<int, int>> q;
        v[0][0] = 1;
        q.push({0, 0});
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            p1 = x;
            p2 = y;
            // cout<<x<<" "<<y<<endl;
            q.pop();
            // if(v==v1){break;}
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                return true;
            }
            if (grid[x][y] == 1)
            {
                if (y < grid[0].size() - 1 && !v[x][y + 1] && (grid[x][y + 1] == 3 || grid[x][y + 1] == 5 || grid[x][y + 1] == 1))
                {
                    v[x][y + 1] = 1;
                    q.push({x, y + 1});
                }
                if (y > 0 && !v[x][y - 1] && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1))
                {
                    v[x][y - 1] = 1;
                    q.push({x, y - 1});
                }
            }
            // if(grid[x][y]==2){
            else if (grid[x][y] == 2)
            {
                if (x < grid.size() - 1 && !v[x + 1][y] && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2))
                {
                    v[x + 1][y] = 1;
                    q.push({x + 1, y});
                }
                if (x > 0 && !v[x - 1][y] && (grid[x - 1][y] == 4 || grid[x - 1][y] == 3 || grid[x - 1][y] == 2))
                {
                    q.push({x - 1, y});
                    v[x - 1][y] = 1;
                }
            }
            else if (grid[x][y] == 3)
            {
                if (x < grid.size() - 1 && !v[x + 1][y] && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2))
                {
                    v[x + 1][y] = 1;
                    q.push({x + 1, y});
                }
                if (y > 0 && !v[x][y - 1] && (grid[x][y - 1] == 4 || grid[x][y - 1] == 6 || grid[x][y - 1] == 1))
                {
                    q.push({x, y - 1});
                    v[x][y - 1] = 1;
                }
            }
            else if (grid[x][y] == 4)
            {
                if (x < grid.size() - 1 && !v[x + 1][y] && (grid[x + 1][y] == 5 || grid[x + 1][y] == 6 || grid[x + 1][y] == 2))
                {
                    v[x + 1][y] = 1;
                    q.push({x + 1, y});
                }
                if (y < grid[0].size() - 1 && !v[x][y + 1] && (grid[x][y + 1] == 1 || grid[x][y + 1] == 3) || grid[x][y + 1] == 5)
                {
                    q.push({x, y + 1});
                    v[x][y + 1] = 1;
                }
            }
            else if (grid[x][y] == 5)
            {
                if (x > 0 && !v[x - 1][y] && (grid[x - 1][y] == 2 || grid[x - 1][y] == 3 || grid[x - 1][y] == 4))
                {
                    v[x - 1][y] = 1;
                    q.push({x - 1, y});
                }
                if (y > 0 && !v[x][y - 1] && (grid[x][y - 1] == 1 || grid[x][y - 1] == 4 || grid[x][y - 1] == 3))
                {
                    q.push({x, y - 1});
                    v[x][y - 1] = 1;
                }
            }
            else if (grid[x][y] == 6)
            {
                if (x > 0 && !v[x - 1][y] && (grid[x - 1][y] == 1 || grid[x - 1][y] == 3 || grid[x - 1][y] == 5))
                {
                    v[x - 1][y] = 1;
                    q.push({x - 1, y});
                }
                if (y < grid[0].size() - 1 && !v[x][y + 1] && (grid[x][y + 1] == 1 || grid[x][y + 1] == 3 || grid[x][y + 1] == 5))
                {
                    q.push({x, y + 1});
                    v[x][y + 1] = 1;
                }
            }
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[0].size(); j++)
            {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        if (p1 != grid.size() - 1 && p2 != grid[0].size() - 1)
        {
            return false;
        }
        if (v[grid.size() - 1][grid[0].size() - 1] == 0)
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> v = {{2, 4, 3}, {6, 5, 2}};
    cout << s.hasValidPath(v);
    return 0;
}