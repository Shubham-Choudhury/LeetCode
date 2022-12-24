// Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        We will never need more than 2 days to disconnect the island.
        There will always be atleast 1 land-cell which will have atmost 2 neighbouring land cells(cell 1)
        Thus, if that land-cell has 2 neighbouring land-cells, our answer is 2 days.
        Else, if that land-cell has only 1 neighbouring land-cell, our answer is 1 day.

        If there are any articulation points, days=1.
        Else days=2.
    */
    vector<vector<int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    vector<bool> visited;
    vector<int> ids;
    vector<int> low_links;
    // vector<bool> ap;
    int flag = 2;

    /*
        We don't need ap vector (Articulation Point vector) here, but I'm maintaining it for template code
        reference. We won't need flag, islands variables in general Articulation point questions.
    */

    void articulationPointsUtil(vector<int> adj[], int id, int parent, int u)
    {
        visited[u] = true;
        ids[u] = low_links[u] = id++;
        int out = 0;

        for (auto v : adj[u])
        {
            if (v == parent)
                continue;
            if (!visited[v])
            {
                out++;
                articulationPointsUtil(adj, id, u, v);
                low_links[u] = min(low_links[u], low_links[v]);

                if (parent == -1 && out > 1)
                {
                    // ap[u] = true;
                    flag = 1;
                }

                if (parent != -1 && ids[u] <= low_links[v])
                {
                    // ap[u] = true;
                    flag = 1;
                }
            }
            else
            {
                low_links[u] = min(low_links[u], ids[v]);
            }
        }
    }

    int articulationPoints(vector<int> adj[], int n)
    {
        visited.resize(n, false);
        ids.resize(n);
        low_links.resize(n);
        // ap.resize(n, false);

        int islands = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                islands++;
                articulationPointsUtil(adj, 0, -1, i);
            }
        }

        return (islands == 1) ? flag : 0;
    }

    int minDays(vector<vector<int>> &grid)
    {
        map<pair<int, int>, int> map;
        int id = 0;
        int m = grid.size(), n = grid[0].size();
        vector<int> adj[m * n];

        if (m * n == 1 && grid[0][0] == 0)
            return 0;
        if (m * n == 1 && grid[0][0] == 1)
            return 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    int u = (map.find({i, j}) != map.end()) ? map[{i, j}] : id++;
                    map[{i, j}] = u;

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1)
                        {
                            int v = (map.find({nx, ny}) != map.end()) ? map[{nx, ny}] : id++;
                            map[{nx, ny}] = v;
                            adj[u].push_back(v);
                        }
                    }

                    if (u > 0 && adj[u].size() == 0)
                        return 0;
                }
            }
        }

        if (id == 1 && adj[id - 1].size() == 0)
            return 1;

        return articulationPoints(adj, id);
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> grid = {{1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 0, 1, 1}, {1, 1, 0, 1, 1}};
    cout << sol.minDays(grid) << endl;
    return 0;
}
