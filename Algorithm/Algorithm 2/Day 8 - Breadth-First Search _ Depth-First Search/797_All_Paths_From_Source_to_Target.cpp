// Link: https://leetcode.com/problems/all-paths-from-source-to-target/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        path.push_back(0);
        dfs(graph, 0, path, result);
        return result;
    }
    
    void dfs(vector<vector<int>>& graph, int node, vector<int>& path, vector<vector<int>>& result) {
        if(node == graph.size() - 1) {
            result.push_back(path);
        } else {
            for(int i = 0; i < graph[node].size(); i++) {
                path.push_back(graph[node][i]);
                dfs(graph, graph[node][i], path, result);
                path.pop_back();
            }
        }
    }
};

int main()
{
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    Solution sol;
    vector<vector<int>> res = sol.allPathsSourceTarget(graph);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}