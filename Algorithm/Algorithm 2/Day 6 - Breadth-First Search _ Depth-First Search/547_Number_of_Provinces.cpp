// Link: https://leetcode.com/problems/number-of-provinces/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                res++;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
        visited[i] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
};

int main() {
    Solution sol;
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    cout << sol.findCircleNum(isConnected) << endl;
    return 0;
}