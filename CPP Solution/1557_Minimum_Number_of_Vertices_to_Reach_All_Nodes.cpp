// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for (auto& edge : edges) {
            indegree[edge[1]]++;
        }
        
        vector<int> result;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges;
    vector<int> result;
    
    edges = {{0,1},{0,2},{2,5},{3,4},{4,2}};
    result = sol.findSmallestSetOfVertices(6, edges);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    edges = {{0,1},{2,1},{3,1},{1,4},{2,4}};
    result = sol.findSmallestSetOfVertices(5, edges);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}