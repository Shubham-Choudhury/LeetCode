// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> visited(1 << n, vector<int>(n, 0));
        queue<vector<int>> q;
        for (int i = 0; i < n; i++){
            q.push({1 << i, i});
            visited[1 << i][i] = 1;
        }
        int ans = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                if (curr[0] == (1 << n) - 1) return ans;
                for (auto a: graph[curr[1]]){
                    int mask = curr[0] | (1 << a);
                    if (!visited[mask][a]){
                        visited[mask][a] = 1;
                        q.push({mask, a});
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }
    Solution obj;
    cout << obj.shortestPathLength(graph) << endl;
    return 0;
}