// Link: https://leetcode.com/problems/sum-of-distances-in-tree/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>> &edges)
    {
        vector<vector<int>> graph(N);
        for (auto &edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<int> count(N, 1);
        vector<int> ans(N, 0);
        dfs(graph, 0, -1, count, ans);
        dfs2(graph, 0, -1, count, ans);
        return ans;
    }

    void dfs(vector<vector<int>> &graph, int node, int parent, vector<int> &count, vector<int> &ans)
    {
        for (int child : graph[node])
        {
            if (child == parent)
            {
                continue;
            }
            dfs(graph, child, node, count, ans);
            count[node] += count[child];
            ans[node] += ans[child] + count[child];
        }
    }

    void dfs2(vector<vector<int>> &graph, int node, int parent, vector<int> &count, vector<int> &ans)
    {
        for (int child : graph[node])
        {
            if (child == parent)
            {
                continue;
            }
            ans[child] = ans[node] - count[child] + count.size() - count[child];
            dfs2(graph, child, node, count, ans);
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> ans = solution.sumOfDistancesInTree(6, edges);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
