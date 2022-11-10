// Link: https://leetcode.com/problems/matrix-block-sum/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int r1 = max(0, i - K);
                int c1 = max(0, j - K);
                int r2 = min(n - 1, i + K);
                int c2 = min(m - 1, j + K);
                ans[i][j] = dp[r2 + 1][c2 + 1] - dp[r1][c2 + 1] - dp[r2 + 1][c1] + dp[r1][c1];
            }
        }
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int K = 1;
    vector<vector<int>> ans = obj.matrixBlockSum(mat, K);
    for (vector<int> i : ans) {
        for (int j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}