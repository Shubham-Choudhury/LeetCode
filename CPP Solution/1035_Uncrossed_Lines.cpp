// Link: https://leetcode.com/problems/uncrossed-lines/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (A[i - 1] == B[j - 1])});
        return dp[n][m];
    }
};

int main()
{
    Solution sol;
    vector<int> A = {1, 4, 2}, B = {1, 2, 4};
    cout << sol.maxUncrossedLines(A, B) << endl;
    return 0;
}
