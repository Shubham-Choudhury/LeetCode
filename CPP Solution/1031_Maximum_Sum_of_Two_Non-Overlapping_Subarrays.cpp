// Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumTwoNoOverlap(vector<int> &A, int L, int M)
    {
        int n = A.size();
        vector<int> sum(n + 1);
        for (int i = 0; i < n; i++)
            sum[i + 1] = sum[i] + A[i];
        int res = 0, maxL = 0, maxM = 0;
        for (int i = L + M; i <= n; i++)
        {
            maxL = max(maxL, sum[i - M] - sum[i - M - L]);
            maxM = max(maxM, sum[i - L] - sum[i - L - M]);
            res = max(res, max(maxL + sum[i] - sum[i - M], maxM + sum[i] - sum[i - L]));
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A = {0, 6, 5, 2, 2, 5, 1, 9, 4};
    int L = 1, M = 2;
    cout << sol.maxSumTwoNoOverlap(A, L, M) << endl;
    return 0;
}

