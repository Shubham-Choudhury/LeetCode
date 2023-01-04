// Link: https://leetcode.com/problems/longest-arithmetic-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
        int longestArithSeqLength(vector<int>& A) {
        int res = 2, n = A.size();
        vector<vector<int>> dp(n, vector<int>(2000, 0));
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)  {
                int d = A[j] - A[i] + 1000;
                dp[j][d] = max(2, dp[i][d] + 1);
                res = max(res, dp[j][d]);
            }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {3, 6, 9, 12};
    cout << sol.longestArithSeqLength(A) << endl;
    return 0;
}
