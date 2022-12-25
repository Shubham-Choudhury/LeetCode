// Link: https://leetcode.com/problems/largest-sum-of-averages/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double largestSumOfAverages(vector<int> &A, int K)
    {
        int n = A.size();
        vector<double> sum(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            sum[i + 1] = sum[i] + A[i];
        }
        vector<vector<double>> dp(n, vector<double>(K + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[i][1] = (sum[n] - sum[i]) / (n - i);
        }
        for (int k = 2; k <= K; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    dp[i][k] = max(dp[i][k], dp[j][k - 1] + (sum[j] - sum[i]) / (j - i));
                }
            }
        }
        return dp[0][K];
    }
};

int main()
{
    Solution sol;
    vector<int> A = {9, 1, 2, 3, 9};
    int K = 3;
    cout << sol.largestSumOfAverages(A, K) << endl;
    return 0;
}
