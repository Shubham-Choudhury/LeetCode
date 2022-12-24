// Link: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unordered_map<int, int> dp;
    int minDays(int n)
    {
        return dfs(n);
    }

    int dfs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (dp.count(n))
            return dp[n];
        int res = INT_MAX;
        if (n % 2 == 0)
            res = min(res, 1 + dfs(n / 2));
        if (n % 3 == 0)
            res = min(res, 1 + dfs(n / 3));
        if ((n - 1) % 2 == 0 || (n - 1) % 3 == 0)
            res = min(res, 1 + dfs(n - 1));
        if ((n - 2) % 3 == 0)
            res = min(res, 2 + dfs(n - 2));
        return dp[n] = res;
    }
};

int main()
{
    Solution sol;
    int n;
    int ans;

    // Output: 2
    n = 10;
    ans = sol.minDays(n);
    cout << ans << endl;

    // Output: 3
    n = 6;
    ans = sol.minDays(n);
    cout << ans << endl;

    // Output: 4
    n = 1;
    ans = sol.minDays(n);
    cout << ans << endl;

    // Output: 6
    n = 56;
    ans = sol.minDays(n);
    cout << ans << endl;

    return 0;
}
