// Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution
{
public:
    // direction vector
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int minPushBox(vector<vector<char>> &grid)
    {
        // rows, cols
        int N = grid.size();
        int M = grid[0].size();

        // intitial position
        int target = -1, box = -1, player = -1;

        // calcluate distance of target, box, player in grid
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (grid[i][j] == 'S')
                {
                    player = i * M + j;
                }
                if (grid[i][j] == 'B')
                {
                    box = i * M + j;
                }
                if (grid[i][j] == 'T')
                {
                    target = i * M + j;
                }
            }
        }
        // set stl to track player-box movement
        // if already visited same path, ignore it
        set<pair<int, int>> visited;
        visited.insert({player, box});

        // declare queue for BFS
        // move box to all it's eligible neighbor
        queue<pair<int, int>> q;
        q.push({player, box});

        int ans = 0;
        while (!q.empty())
        {

            ans++;

            // size of neighbor to be visited
            int size = q.size();

            while (size--)
            {

                auto f = q.front();
                q.pop();

                // current box position
                int box_curr = f.second;
                // get box position in matrix
                int box_x = box_curr / M;
                int box_y = box_curr % M;
                // palyer position
                int p = f.first;

                // make grid with box as obstacle
                grid[box_x][box_y] = '#';

                for (auto &d : dir)
                {

                    int new_box_x = box_x + d[0];
                    int new_box_y = box_y + d[1];

                    int px = box_x - d[0];
                    int py = box_y - d[1];

                    // to be used in dfs walk by player to reach box
                    vector<vector<int>> walk(N, vector<int>(M, 0));

                    if (isValid(grid, new_box_x, new_box_y) && canWalk(grid, p / M, p % M, px, py, walk) && visited.count({px * M + py, new_box_x * M + new_box_y}) == 0)
                    {

                        if (new_box_x == target / M && new_box_y == target % M)
                            return ans;

                        visited.insert({px * M + py, new_box_x * M + new_box_y});
                        q.push({px * M + py, new_box_x * M + new_box_y});
                    }
                }
                grid[box_x][box_y] = '.';
            }
        }

        return -1;
    }

    bool isValid(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#')
            return false;

        return true;
    }

    bool canWalk(vector<vector<char>> &grid, int x, int y, int i, int j, vector<vector<int>> &walk)
    {
        if (x == i && y == j)
            return true;

        for (auto &d : dir)
        {
            int nx = x + d[0], ny = y + d[1];
            if (isValid(grid, nx, ny) && walk[nx][ny] == 0)
            {
                walk[nx][ny] = 1;
                if (canWalk(grid, nx, ny, i, j, walk))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> grid = {{'#', '#', '#', '#', '#', '#'},
                                 {'#', 'T', '#', '#', '#', '#'},
                                 {'#', '.', '.', 'B', '.', '#'},
                                 {'#', '.', '#', '#', '.', '#'},
                                 {'#', '.', '.', '.', 'S', '#'},
                                 {'#', '#', '#', '#', '#', '#'}};
    cout << s.minPushBox(grid) << endl;
    return 0;
}
