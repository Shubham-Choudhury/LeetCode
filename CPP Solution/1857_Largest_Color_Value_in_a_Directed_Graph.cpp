// Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPathValue(string colors, vector<vector<int>> &edges)
    {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto v : adj[u])
            {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        if (topo.size() != n)
            return -1;
        vector<vector<int>> dp(n, vector<int>(26, 0));
        int ans = 0;
        for (auto u : topo)
        {
            dp[u][colors[u] - 'a']++;
            for (auto v : adj[u])
            {
                for (int i = 0; i < 26; i++)
                {
                    dp[v][i] = max(dp[v][i], dp[u][i]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string colors;
    vector<vector<int>> edges;
    int ans;

    // Output: 4
    colors = "abaca", edges = {{0, 1}, {0, 2}, {2, 3}, {3, 4}};

    // Output: 3
    // colors = "a", edges = {{0, 0}};

    ans = sol.largestPathValue(colors, edges);
    cout << ans << endl;

    return 0;
}
