// Link: https://leetcode.com/problems/maximize-number-of-nice-divisors/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

long long go(int x, int p)
{
    if (x == 1)
        return 1;
    if (p == 0)
        return 1;

    long long y = go(x, p / 2) % mod;

    y = (y * y) % mod;

    if (p & 1)
        y = (y * x) % mod;

    return y;
}

class Solution
{
public:
    int maxNiceDivisors(int N)
    {

        if (N == 1)
            return 1;
        if (N == 2)
            return 2;
        if (N == 3)
            return 3;

        int a = N % 3;

        if (a == 0)
            return go(3, N / 3) % mod;
        if (a == 1)
            return (4LL * go(3, N / 3 - 1)) % mod;
        else
            return (2LL * go(3, N / 3)) % mod;
    }
};

int main()
{
    Solution sol;
    int primeFactors, ans;

    // Output: 6
    primeFactors = 5;
    ans = sol.maxNiceDivisors(primeFactors);
    cout << ans << endl;

    // Output: 18
    primeFactors = 8;
    ans = sol.maxNiceDivisors(primeFactors);
    cout << ans << endl;

    return 0;
}