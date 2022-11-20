// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    
        vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.size() == 0)
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            dfs(matrix, pacific, INT_MIN, i, 0);
            dfs(matrix, atlantic, INT_MIN, i, n - 1);
        }
        for(int j = 0; j < n; j++){
            dfs(matrix, pacific, INT_MIN, 0, j);
            dfs(matrix, atlantic, INT_MIN, m - 1, j);
        }
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});
        return res;
    }
    
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int height, int i, int j){
        int m = matrix.size();
        int n = matrix[0].size();
        if(i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || matrix[i][j] < height)
            return;
        visited[i][j] = true;
        dfs(matrix, visited, matrix[i][j], i + 1, j);
        dfs(matrix, visited, matrix[i][j], i - 1, j);
        dfs(matrix, visited, matrix[i][j], i, j + 1);
        dfs(matrix, visited, matrix[i][j], i, j - 1);
    }
    
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 2, 3, 5},
                                  {3, 2, 3, 4, 4},
                                  {2, 4, 5, 3, 1},
                                  {6, 7, 1, 4, 5},
                                  {5, 1, 1, 2, 4}};
    Solution s;
    vector<vector<int>> res = s.pacificAtlantic(matrix);
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}