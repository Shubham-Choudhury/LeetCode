// Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

#include <iostream>
#include <cstring>
using namespace std;

class Solution
{
public:
    int dp[55][105][55];
    int mod = 1e9 + 7;
    int n, m;

    long long int power(long long int x, long long int y)
    {
        long long int res = 1;
        while (y)
        {
            if (y & 1)
                res = (res * x) % mod;
            x = (x * x) % mod;
            y >>= 1;
        }
        return res;
    }

    int kil(int idx, int maxVal, int k)
    {
        if (idx == n)
        {
            if (k == 0)
                return 1;
            return 0;
        }

        if (k < 0)
            return 0;

        if (dp[idx][maxVal][k] != -1)
            return dp[idx][maxVal][k];

        if (k == 0)
        {
            dp[idx][maxVal][k] = power(maxVal, n - idx);
            return dp[idx][maxVal][k];
        }

        dp[idx][maxVal][k] = 0;

        for (int i = 1; i <= m; i++)
            dp[idx][maxVal][k] = (dp[idx][maxVal][k] + kil(idx + 1, max(i, maxVal), (i > maxVal) ? k - 1 : k)) % mod;

        return dp[idx][maxVal][k];
    }

    int numOfArrays(int n1, int m1, int k)
    {
        m = m1;
        n = n1;
        memset(dp, -1, sizeof dp);
        return kil(0, 0, k);
    }
};

int main(void)
{
    Solution sol;
    int n = 2;
    int m = 3;
    int k = 1;
    int res = sol.numOfArrays(n, m, k);
    cout << res << endl;
    return 0;
}
