// Link: https://leetcode.com/problems/strange-printer/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution
{
public:
    int dp[1005][1005];

    int kil(int l, int r, string &s)
    {
        if (l > r)
            return 0;
        if (l == r)
            return 1;

        if (dp[l][r] != -1)
            return dp[l][r];

        dp[l][r] = 1 + kil(l + 1, r, s);

        for (int i = l + 1; i <= r; i++)
        {

            if (s[l] == s[i])
                dp[l][r] = min(dp[l][r], kil(l + 1, i, s) + kil(i + 1, r, s));
        }
        return dp[l][r];
    }

    int strangePrinter(string s)
    {
        memset(dp, -1, sizeof dp);
        return kil(0, s.length() - 1, s);
    }
};

int main()
{
    Solution sol;
    string s = "aaabbb";
    cout << sol.strangePrinter(s) << endl;
    return 0;
}