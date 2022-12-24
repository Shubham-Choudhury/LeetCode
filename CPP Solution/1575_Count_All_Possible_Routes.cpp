// Link: https://leetcode.com/problems/count-all-possible-routes/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int n;
    int MOD = 1e9 + 7;

    // Since number of locations is small we can use adjacency matrix
    int adj[105][105];

    // There will be overlapping subproblems hence to avoid calculating
    // distances for same source, dest, and fuel we use memoization
    int dp[105][105][205];

public:
    int dfs(int node, int dest, int fuel_left)
    {

        if (dp[node][dest][fuel_left] != -1)
            return dp[node][dest][fuel_left];
        int total = 0;

        if (node == dest)
        {
            // We don't return from here so that we can explore more paths
            // for eg if source=1 and dest=0 then paths like 1->0->1->0
            // will not get explored if we return
            ++total;
        }
        if (fuel_left == 0)
            return total;

        for (int i = 0; i < n; ++i)
        {
            if (adj[node][i] != -1 && (fuel_left - adj[node][i]) >= 0)
            {
                total = (total + dfs(i, dest, fuel_left - adj[node][i])) % MOD;
            }
        }
        dp[node][dest][fuel_left] = total;
        return total;
    }

    int countRoutes(vector<int> &loc, int start, int finish, int fuel)
    {
        n = loc.size();

        memset(adj, -1, sizeof(adj));
        memset(dp, -1, sizeof(dp));

        // Create an undirected graph
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                adj[i][j] = abs(loc[i] - loc[j]);
                adj[j][i] = abs(loc[i] - loc[j]);
            }
        }

        return dfs(start, finish, fuel);
    }
};

int main()
{
    Solution sol;
    vector<int> locations = {2, 3, 6, 8, 4};
    cout << sol.countRoutes(locations, 1, 3, 5) << endl;
    cout << sol.countRoutes(locations, 2, 1, 5) << endl;
    cout << sol.countRoutes(locations, 1, 0, 3) << endl;
    cout << sol.countRoutes(locations, 0, 3, 3) << endl;
    return 0;
}
