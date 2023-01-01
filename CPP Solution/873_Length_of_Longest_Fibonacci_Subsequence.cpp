// Link: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenLongestFibSubseq(vector<int> &A)
    {
        int n = A.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[A[i]] = i;
        }
        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (m.find(A[j] - A[i]) != m.end())
                {
                    int k = m[A[j] - A[i]];
                    if (k < i)
                    {
                        dp[i][j] = dp[k][i] + 1;
                    }
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans > 2 ? ans : 0;
    }
};

int main()
{
    Solution s;
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << s.lenLongestFibSubseq(A) << endl;
    return 0;
}
