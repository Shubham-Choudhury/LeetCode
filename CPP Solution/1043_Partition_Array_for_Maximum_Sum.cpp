// Link: https://leetcode.com/problems/partition-array-for-maximum-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &A, int K)
    {
        int n = A.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            int mx = 0;
            for (int k = 1; k <= K && i - k + 1 >= 0; k++)
            {
                mx = max(mx, A[i - k + 1]);
                dp[i] = max(dp[i], (i >= k ? dp[i - k] : 0) + mx * k);
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 15, 7, 9, 2, 5, 10};
    int K = 3;
    cout << sol.maxSumAfterPartitioning(A, K) << endl;
    return 0;
}
