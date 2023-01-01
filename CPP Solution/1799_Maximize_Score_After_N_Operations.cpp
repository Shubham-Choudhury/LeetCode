// Link: https://leetcode.com/problems/maximize-score-after-n-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Choose two elements, x and y.
Receive a score of i * gcd(x, y).
Remove x and y from nums.
*/
    int dfs(int op, int &vis, vector<int> &v, int &n, vector<int> &dp)
    {
        if (op > n)
            return 0;
        if (dp[vis])
            return dp[vis];
        int z = 0;
        for (int i = 0; i < 2 * n; i++)
        {
            if (!(vis & (1 << i)))
            {
                vis |= 1 << i; // mark the place as visited
                for (int j = 0; j < 2 * n; j++)
                {
                    if (i != j and !(vis & (1 << j)))
                    {
                        vis |= 1 << j;                                                   // mark the place as visited
                        z = max(z, op * __gcd(v[i], v[j]) + dfs(op + 1, vis, v, n, dp)); // compute value and call the function
                        vis &= ~(1 << j);                                                // unmark
                    }
                }
                vis &= ~(1 << i); // unmark
            }
        }
        return dp[vis] = z; // cache
    }
    int maxScore(vector<int> &nums)
    {
        int vis = 0;
        int n = nums.size() / 2;
        vector<int> dp(1 << (2 * n) + 1);
        return dfs(1, vis, nums, n, dp);
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int ans;

    // Output: 14
    nums = {1, 2};
    ans = sol.maxScore(nums);
    cout << ans << endl;

    // Output: 14
    nums = {3, 4, 2};
    ans = sol.maxScore(nums);
    cout << ans << endl;

    // Output: 142
    nums = {1, 2, 3, 4, 5, 6};
    ans = sol.maxScore(nums);
    cout << ans << endl;

    return 0;
}
