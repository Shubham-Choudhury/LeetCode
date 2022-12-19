// Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = arr[0][i];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (j != k)
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << s.minFallingPathSum(arr) << endl;
    return 0;
}
