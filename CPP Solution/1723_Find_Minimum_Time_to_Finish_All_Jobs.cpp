// Link: https://leetcode.com/problems/find-minimum-time-to-finish-all-jobs/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTimeRequired(vector<int> &jobs, int k)
    {
        int n = jobs.size();
        vector<int> sum(1 << n);
        for (int i = 1; i < (1 << n); i++)
        {
            int x = __builtin_ctz(i);
            sum[i] = sum[i ^ (1 << x)] + jobs[x];
        }
        vector<vector<int>> dp(k, vector<int>(1 << n, INT_MAX / 2));
        for (int i = 0; i < (1 << n); i++)
        {
            dp[0][i] = sum[i];
        }
        for (int i = 1; i < k; i++)
        {
            for (int j = 0; j < (1 << n); j++)
            {
                for (int s = j; s; s = (s - 1) & j)
                {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j ^ s], sum[s]));
                }
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};

int main()
{
    Solution sol;
    vector<int> jobs;
    int k, result;

    // Output: 3
    jobs = {3, 2, 3}, k = 3;
    result = sol.minimumTimeRequired(jobs, k);
    cout << result << endl;

    // Output: 11
    jobs = {1, 2, 4, 7, 8}, k = 2;
    result = sol.minimumTimeRequired(jobs, k);
    cout << result << endl;

    return 0;
}
