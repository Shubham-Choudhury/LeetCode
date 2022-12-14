// Link: https://leetcode.com/problems/longest-common-subpath/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution
{
public:
    ll base, MOD;
    vector<ll> p;

    bool works(ll len, vector<vector<int>> &paths, ll m)
    {
        unordered_set<ll> s;
        for (ll i = 0; i < m; i++)
        {
            if (paths[i].size() < len)
            {
                return false;
            }
            unordered_set<ll> ss;
            ll hash = 0;
            for (ll j = 0; j < len; j++)
            {
                hash = (hash + (((ll)(paths[i][j] + 1) * p[len - 1 - j]) % MOD)) % MOD;
            }
            if (i == 0)
            {
                s.insert(hash);
            }
            else
            {
                if (s.find(hash) != s.end())
                {
                    ss.insert(hash);
                }
            }
            for (ll j = len; j < paths[i].size(); j++)
            {
                hash = (hash + MOD - (((ll)(paths[i][j - len] + 1) * p[len - 1]) % MOD)) % MOD;
                hash = (ll)hash * base % MOD;
                hash = (hash + paths[i][j] + 1) % MOD;
                if (i == 0)
                {
                    s.insert(hash);
                }
                else
                {
                    if (s.find(hash) != s.end())
                    {
                        ss.insert(hash);
                    }
                }
            }
            if (i > 0)
            {
                s = ss;
            }
            if (s.size() == 0)
            {
                return false;
            }
        }
        if (s.size() > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        ll l = 0, r = 1e9L, m = paths.size();
        base = 100007, MOD = 1e11L + 7;
        for (ll i = 0; i < m; i++)
        {
            r = min(r, (ll)paths[i].size());
        }
        p = vector<ll>(r);
        p[0] = 1;
        for (ll i = 1; i < r; i++)
        {
            p[i] = (ll)base * p[i - 1] % MOD;
        }
        while (l < r)
        {
            ll mid = (l + r + 1) / 2;
            if (works(mid, paths, m))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        return r;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{0, 1, 2, 3, 4}, {2, 3, 4}, {4, 0, 1, 2, 3}};
    cout << a.longestCommonSubpath(5, b) << endl;
    return 0;
}