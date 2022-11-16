// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        if (n == 1)
            return 1;

        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int level = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> curr = q.front();
                q.pop();

                if (curr.first == n - 1 && curr.second == n - 1)
                    return level;

                for (int i = 0; i < 8; i++)
                {
                    int x = curr.first + dx[i];
                    int y = curr.second + dy[i];

                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        q.push({x, y});
                        grid[x][y] = 1;
                    }
                }
            }
            level++;
        }

        return -1;
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    Solution obj;
    cout << obj.shortestPathBinaryMatrix(grid);

    return 0;
}