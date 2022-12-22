// Link: https://leetcode.com/problems/redundant-connection/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i)
            parent[i] = i;
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1];
            if (find(parent, u) == find(parent, v))
                return edge;
            parent[find(parent, u)] = find(parent, v);
        }
        return {};
    }

private:
    int find(vector<int> &parent, int i)
    {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    vector<int> res = obj.findRedundantConnection(edges);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}
