// Link: https://leetcode.com/problems/number-of-ways-to-reconstruct-a-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int checkWays(vector<vector<int>> &pairs)
    {
        int links[500] = {0};
        vector<vector<int>> adj(500);
        vector<vector<bool>> isPair(500, vector<bool>(500));
        for (auto &p : pairs)
        {
            int u = p[0];
            int v = p[1];
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            isPair[u][v] = true;
            isPair[v][u] = true;
            ++links[u];
            ++links[v];
        }
        int numNodes = 0;
        int maxLinks = 0;
        int root = -1;
        for (int i = 0; i < 500; i++)
        {
            numNodes += links[i] > 0;
            if (links[i] > maxLinks)
            {
                maxLinks = links[i];
                root = i;
            }
            // sort to guarantee (3) is always true
            sort(adj[i].begin(), adj[i].end(), [&](int l, int r)
                 { return links[l] > links[r]; });
            // just to make the bottom check on line 43 easier in the entry case where
            // the parent of the root is the root
            isPair[i][i] = true;
        }
        if (links[root] != numNodes - 1)
        {
            // (4) fails
            return 0;
        }
        bool seen[500] = {0};
        vector<vector<int>> graph(500);
        bool canSwap = false;
        function<bool(int, int)> dfs = [&](int node, int par)
        {
            seen[node] = true;
            for (int chi : adj[node])
            {
                // cannot construct
                if (!isPair[par][chi])
                {
                    // (3) fails
                    return false;
                }
                if (seen[chi])
                {
                    continue;
                }
                graph[node].push_back(chi);
                if (links[node] == links[chi])
                {
                    // case in observation (5) is true
                    canSwap = true;
                }
                if (!dfs(chi, node))
                {
                    return false;
                }
            }
            return true;
        };
        if (dfs(root, root))
        {
            return canSwap ? 2 : 1;
        }
        return 0;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> in = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    cout << a.checkWays(in) << endl;
    return 0;
}
