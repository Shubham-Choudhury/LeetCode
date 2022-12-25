// Link: https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n, m, dp[1001][1001], mod = 1e9 + 7;
    string t;
    vector<vector<int>> v;

    int sol(int i, int j)
    {
        if (j == m)
            return 1;
        if (m - j > n - i)
            return 0;

        long ans = dp[i][j];
        if (ans != -1)
            return ans;

        ans = sol(i + 1, j);
        ans = (ans + (long)v[i][t[j] - 'a'] * sol(i + 1, j + 1));

        return dp[i][j] = ans % mod;
    }

    int numWays(vector<string> &s, string tt)
    {
        t = tt;
        n = s[0].length();
        m = t.length();
        v.resize(n, vector<int>(26, 0));
        for (int i = 0; i < s.size(); i++)
            for (int j = 0; j < n; j++)
                v[j][s[i][j] - 'a']++;
        memset(dp, -1, sizeof(dp));
        return sol(0, 0);
    }
};

int main()
{
    Solution a;
    vector<string> b = {"acca", "bbbb", "caca"};
    cout << a.numWays(b, "aba");
    return 0;
}