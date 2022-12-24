// Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> ans(2);
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });

        int minCost = kruskal(n, edges, parent, -1, -1);

        for (int i = 0; i < edges.size(); i++)
        {
            int cost = kruskal(n, edges, parent, i, -1);
            if (cost > minCost)
                ans[0].push_back(edges[i][3]);
            else
            {
                cost = kruskal(n, edges, parent, -1, i);
                if (cost == minCost)
                    ans[1].push_back(edges[i][3]);
            }
        }

        return ans;
    }

    int kruskal(int n, vector<vector<int>> &edges, vector<int> &parent, int skipEdge, int takeEdge)
    {
        int cost = 0;
        int count = 0;
        iota(parent.begin(), parent.end(), 0);

        if (takeEdge != -1)
        {
            cost += edges[takeEdge][2];
            count++;
            parent[edges[takeEdge][1]] = edges[takeEdge][0];
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == skipEdge)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];

            int pu = find(u, parent);
            int pv = find(v, parent);

            if (pu != pv)
            {
                cost += edges[i][2];
                count++;
                parent[pv] = pu;
            }
        }

        if (count != n - 1)
            return INT_MAX;

        return cost;
    }

    int find(int u, vector<int> &parent)
    {
        if (u == parent[u])
            return u;

        return parent[u] = find(parent[u], parent);
    }
};

int main()
{
    Solution a;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
    vector<vector<int>> ans = a.findCriticalAndPseudoCriticalEdges(5, edges);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
