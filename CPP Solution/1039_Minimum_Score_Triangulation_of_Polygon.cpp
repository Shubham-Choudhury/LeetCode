// Link: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int> &A)
    {
        int n = A.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i)
            for (int j = i + 2; j < n; ++j)
            {
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
            }
        return dp[0][n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 2, 3};
    cout << sol.minScoreTriangulation(A) << endl;
    return 0;
}
