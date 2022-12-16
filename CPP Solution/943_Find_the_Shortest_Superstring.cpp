// Link: https://leetcode.com/problems/find-the-shortest-superstring/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;

vector<vector<int>> dp, pre, par;

bool startWith(string s, string t)
{
    int i;
    for (i = 0; i < s.length() && i < t.length(); i++)
    {
        if (s[i] == t[i])
            continue;
        else
            return false;
    }
    if (i == t.length())
        return true;
    else
        return false;
}

int calc(string A, string B)
{

    int a = A.length(), b = B.length();
    for (int i = 0; i < a; i++)
    {
        if (a - i <= b && startWith(B, A.substr(i)))
        {
            return b - (a - i);
        }
    }
    return b;
}

int finalMask, n;

int helper(int mask, int last)
{

    if (mask == finalMask)
        return 0;

    if (dp[mask][last] != -1)
        return dp[mask][last];

    int mn = INT_MAX;
    int p;
    for (int i = 0; i < n; i++)
    {
        if (mask & (1 << i))
            continue;
        int cost = pre[last][i] + helper(mask | (1 << i), i);
        if (cost < mn)
        {
            mn = cost;
            p = i;
        }
    }
    par[mask][last] = p;
    return dp[mask][last] = mn;
}

class Solution
{
public:
    string shortestSuperstring(vector<string> &A)
    {
        n = A.size();
        pre.assign(n, vector<int>(n));
        par.assign(1 << n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                pre[i][j] = calc(A[i], A[j]);
            }
        }
        finalMask = (1 << n) - 1;
        dp.assign(1 << n, vector<int>(n, -1));
        int len = INT_MAX;
        int ind;
        for (int i = 0; i < n; i++)
        {
            int prev = len;
            len = min(len, (int)A[i].length() + helper(1 << i, i));
            if (len != prev)
            {
                ind = i;
            }
        }

        string ans = A[ind];
        int msk = 1 << ind;
        int prev_ind = ind;
        ind = par[msk][ind];
        while (ind != -1)
        {
            len = pre[prev_ind][ind];
            int alen = A[ind].length();
            ans += A[ind].substr(alen - len, len);
            msk = msk ^ (1 << ind);
            prev_ind = ind;
            ind = par[msk][ind];
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<string> b = {"alex", "loves", "leetcode"};
    cout << a.shortestSuperstring(b) << endl;
    return 0;
}
