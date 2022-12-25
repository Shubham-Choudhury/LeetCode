// Link: https://leetcode.com/problems/binary-trees-with-factors/

#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &A)
    {
        int n = A.size();
        sort(A.begin(), A.end());
        unordered_map<int, long> dp;
        for (int i = 0; i < n; i++)
        {
            dp[A[i]] = 1;
            for (int j = 0; j < i; j++)
            {
                if (A[i] % A[j] == 0)
                {
                    dp[A[i]] += dp[A[j]] * dp[A[i] / A[j]];
                }
            }
        }
        long res = 0;
        for (auto it : dp)
        {
            res += it.second;
        }
        return res % (int)(1e9 + 7);
    }
};

int main()
{
    Solution sol;
    vector<int> A = {2, 4};
    cout << sol.numFactoredBinaryTrees(A) << endl;
    return 0;
}
