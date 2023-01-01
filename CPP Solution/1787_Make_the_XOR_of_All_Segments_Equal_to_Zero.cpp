// Link: https://leetcode.com/problems/make-the-xor-of-all-segments-equal-to-zero/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minChanges(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<unordered_map<int, int>> cnts(k);
        for (int i = 0; i < n; ++i)
            ++cnts[i % k][nums[i]];

        // case 1: one number is not from list
        vector<int> mxs;
        int tot_mx = 0, mn = INT_MAX;
        auto comp = [](auto x, auto y)
        { return x.second < y.second; };
        for (int i = 0; i < k; ++i)
        {
            int mx = max_element(begin(cnts[i]), end(cnts[i]), comp)->second;
            tot_mx += mx;
            mn = min(mn, mx);
        }
        int case1 = n - (tot_mx - mn);

        // case 2: all k numbers are from list
        unordered_map<int, int> dp{{0, 0}}, dp2;
        for (int i = 0; i < k; ++i)
        {
            dp2.clear();
            for (auto &x : dp)
                for (auto &y : cnts[i])
                {
                    int t = x.first ^ y.first;
                    dp2[t] = max(dp2[t], x.second + y.second);
                }
            dp.swap(dp2);
        }

        return min(case1, n - dp[0]);
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int k, ans;

    // Output: 3
    nums = {1, 2, 0, 3, 0}, k = 1;
    ans = sol.minChanges(nums, k);
    cout << ans << endl;

    // Output: 3
    nums = {3, 4, 5, 2, 1, 7, 3, 4, 7}, k = 3;
    ans = sol.minChanges(nums, k);
    cout << ans << endl;

    // Output: 0
    nums = {1, 2, 4, 1, 2, 5, 1, 2, 6}, k = 3;
    ans = sol.minChanges(nums, k);
    cout << ans << endl;

    return 0;
}
