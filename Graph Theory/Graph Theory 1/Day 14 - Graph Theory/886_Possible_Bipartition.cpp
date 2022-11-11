// Link: https://leetcode.com/problems/possible-bipartition/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N + 1);
        for (auto& dislike : dislikes) {
            graph[dislike[0]].push_back(dislike[1]);
            graph[dislike[1]].push_back(dislike[0]);
        }
        
        vector<int> color(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0 && !dfs(graph, color, i, 1)) {
                return false;
            }
        }
        return true;
    }

private:

    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == c) {
                return false;
            }
            if (color[neighbor] == 0 && !dfs(graph, color, neighbor, -c)) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> dislikes;
    bool result;
    
    dislikes = {{1,2},{1,3},{2,4}};
    result = sol.possibleBipartition(4, dislikes);
    cout << result << endl;
    
    dislikes = {{1,2},{1,3},{2,3}};
    result = sol.possibleBipartition(3, dislikes);
    cout << result << endl;
    
    dislikes = {{1,2},{2,3},{3,4},{4,5},{1,5}};
    result = sol.possibleBipartition(5, dislikes);
    cout << result << endl;
    
    return 0;
}

