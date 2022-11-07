// Link: https://leetcode.com/problems/find-eventual-safe-states/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (dfs(graph, i, color)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool dfs(vector<vector<int>>& graph, int u, vector<int>& color) {
        if (color[u] > 0) {
            return color[u] == 2;
        }
        color[u] = 1;
        for (int v : graph[u]) {
            if (color[v] == 2) {
                continue;
            }
            if (color[v] == 1 || !dfs(graph, v, color)) {
                return false;
            }
        }
        color[u] = 2;
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    Solution obj;
    vector<int> ans = obj.eventualSafeNodes(graph);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}