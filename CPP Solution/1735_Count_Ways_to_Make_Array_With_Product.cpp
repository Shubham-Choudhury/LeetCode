// Link: https://leetcode.com/problems/count-ways-to-make-array-with-product/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
#define ll long long
#define mod 1000000007
    ll dp[20001];

    void pre()
    {
        dp[0] = 1;
        for (int i = 1; i < 20001; i++)
            dp[i] = dp[i - 1] * i % mod;
    }

    ll inverseModulo(ll a, ll p)
    {
        ll xa = 1, xp = 0, xr, q, u = p, r;
        while (p)
        {
            q = a / p;
            xr = xa - q * xp;
            xa = xp;
            xp = xr;
            r = a % p;
            a = p;
            p = r;
        }
        xa = (xa + u) % u;
        return xa;
    }

    ll choose(int a, int b)
    {
        return dp[a] * inverseModulo(dp[a - b], mod) % mod * inverseModulo(dp[b], mod) % mod;
    }

    int positiveCount(int n, int k)
    {
        ll res = 1;
        int pc = 0;
        while (!(k % 2))
        {
            k = k / 2;
            pc++;
        }
        res = res * choose(pc + n - 1, n - 1) % mod;
        for (int i = 3; i * i <= k; i += 2)
        {
            if (!(k % i))
            {
                pc = 0;
                while (!(k % i))
                {
                    k = k / i;
                    pc++;
                }
                res = res * choose(pc + n - 1, n - 1) % mod;
            }
        }
        if (k > 1)
            res = res * n % mod;
        return (int)res;
    }

    vector<int> waysToFillArray(vector<vector<int>> &queries)
    {
        int c = queries.size();
        vector<int> res(c);
        pre();
        for (int i = 0; i < c; i++)
        {
            res[i] = positiveCount(queries[i][0], queries[i][1]);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> queries;
    vector<int> result;

    // Output: [6,4,0]
    queries = {{2, 6}, {5, 1}, {73, 660}};
    result = sol.waysToFillArray(queries);
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    // Output: [1,2,3,0]
    queries = {{1, 1}, {2, 2}, {3, 3}, {4, 4}};
    result = sol.waysToFillArray(queries);
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    // Output: [1,2,4,2,1]
    queries = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
    result = sol.waysToFillArray(queries);
    for (auto x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}