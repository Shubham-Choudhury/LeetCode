// Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                maxLen = max(maxLen, dfs(matrix, cache, i, j));
        return maxLen;
    }
    
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& cache, int i, int j) {
        if (cache[i][j] != 0)
            return cache[i][j];
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 1;
        if (i > 0 && matrix[i - 1][j] > matrix[i][j])
            maxLen = max(maxLen, 1 + dfs(matrix, cache, i - 1, j));
        if (i < m - 1 && matrix[i + 1][j] > matrix[i][j])
            maxLen = max(maxLen, 1 + dfs(matrix, cache, i + 1, j));
        if (j > 0 && matrix[i][j - 1] > matrix[i][j])
            maxLen = max(maxLen, 1 + dfs(matrix, cache, i, j - 1));
        if (j < n - 1 && matrix[i][j + 1] > matrix[i][j])
            maxLen = max(maxLen, 1 + dfs(matrix, cache, i, j + 1));
        cache[i][j] = maxLen;
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix;
    int res;
    
    // Output: 4
    matrix = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    res = sol.longestIncreasingPath(matrix);
    cout << res << endl;
    
    // Output: 4
    matrix = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    res = sol.longestIncreasingPath(matrix);
    cout << res << endl;
    
    return 0;
}

