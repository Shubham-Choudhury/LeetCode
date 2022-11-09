// Link: https://leetcode.com/problems/is-graph-bipartite/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        for (int i = 0; i < n; i++) {
            if (color[i] == 0) {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (int neighbor : graph[node]) {
                        if (color[neighbor] == 0) {
                            color[neighbor] = -color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph;
    bool result;
    
    graph = {{1,3},{0,2},{1,3},{0,2}};
    result = sol.isBipartite(graph);
    cout << result << endl;
    
    graph = {{1,2,3},{0,2},{0,1,3},{0,2}};
    result = sol.isBipartite(graph);
    cout << result << endl;
    
    return 0;
}