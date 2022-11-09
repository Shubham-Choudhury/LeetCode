// Link: https://leetcode.com/problems/minimum-falling-path-sum/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < m; i++)
            dp[0][i] = matrix[0][i];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] = dp[i - 1][j];
                if(j > 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                if(j < m - 1)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < m; i++)
            ans = min(ans, dp[n - 1][i]);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout << s.minFallingPathSum(matrix) << endl;
    return 0;
}