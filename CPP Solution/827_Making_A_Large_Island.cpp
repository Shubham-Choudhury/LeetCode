// Link: https://leetcode.com/problems/making-a-large-island/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int island = 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    int size = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = island;
                    while (!q.empty())
                    {
                        auto cur = q.front();
                        q.pop();
                        size++;
                        for (auto d : dir)
                        {
                            int x = cur.first + d[0];
                            int y = cur.second + d[1];
                            if (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] == 1)
                            {
                                grid[x][y] = island;
                                q.push({x, y});
                            }
                        }
                    }
                    mp[island] = size;
                    island++;
                }
            }
        }

        int ans = 0;
        for (auto it : mp)
        {
            ans = max(ans, it.second);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                {
                    unordered_set<int> st;
                    for (auto d : dir)
                    {
                        int x = i + d[0];
                        int y = j + d[1];
                        if (x >= 0 and x < n and y >= 0 and y < m and grid[x][y] != 0)
                        {
                            st.insert(grid[x][y]);
                        }
                    }
                    int size = 1;
                    for (auto it : st)
                    {
                        size += mp[it];
                    }
                    ans = max(ans, size);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> in = {{1, 0}, {0, 1}};
    cout << a.largestIsland(in) << endl;
    return 0;
}
