// Link: https://leetcode.com/problems/critical-connections-in-a-network/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
#include <climits>
using namespace std;

#define pb push_back
class Solution
{
private:
    vector<vector<int>> neighbors; // graph by neighbors
    vector<int> rank;              // node rank by DFS
    vector<int> low;               // node low-link value: lowest rank the node can reach by DFS (inlcuding itself)
    vector<vector<int>> bridges;   // critical connections

    // build graph by creating neighbor lists
    void buildGraph(int n, vector<vector<int>> &connections)
    {
        neighbors.resize(n);
        for (const auto &edge : connections)
        {
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
    }

    // DFS to label ranks and compute low-link values for all nodes
    // while identifying bridges if low[node] > rank[parent]
    void dfs(int node, int parent, int &r)
    {
        if (rank[node] > 0)
            return; // skip visited nodes

        rank[node] = low[node] = r++; // initialize rank and low-link

        for (int neighbor : neighbors[node])
        {
            if (neighbor == parent)
                continue;

            if (rank[neighbor] == 0)
                dfs(neighbor, node, r);                // DFS
            low[node] = min(low[node], low[neighbor]); // update low-link
        }

        // condition to identify bridges
        if (parent != -1 && low[node] > rank[parent])
            bridges.push_back({parent, node});
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        rank.resize(n);
        low.resize(n);
        buildGraph(n, connections);

        int r = 1; // initial rank of node 0
        dfs(0, -1 /*no parent*/, r);

        return bridges;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    vector<vector<int>> result = s.criticalConnections(4, connections);
    for (auto &v : result)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}