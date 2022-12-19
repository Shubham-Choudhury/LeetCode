// Link: https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> graph(n);
        for (auto& edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (cur == end)
                return true;
            for (int next: graph[cur])
            {
                if (!visited[next])
                {
                    q.push(next);
                    visited[next] = true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    int n, start, end;
    vector<vector<int>> edges;
    bool res;

    // Output: true
    n = 3, edges = {{0,1},{1,2},{2,0}}, start = 0, end = 2;
    res = sol.validPath(n, edges, start, end);
    cout << res << endl;

    // Output: false
    n = 6, edges = {{0,1},{0,2},{3,5},{5,4},{4,3}}, start = 0, end = 5;
    res = sol.validPath(n, edges, start, end);
    cout << res << endl;

    return 0;
}
