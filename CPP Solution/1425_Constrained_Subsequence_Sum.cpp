// Link: https://leetcode.com/problems/constrained-subsequence-sum/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include <deque>
using namespace std;

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> q; // store indices
        vector<int> dp(n, INT_MIN);
        for (int i = 0; i < nums.size(); i++)
        {
            dp[i] = nums[i];
        }
        dp[0] = nums[0];
        q.push_back(0);

        for (int i = 1; i < nums.size(); i++)
        {
            while (!q.empty() && q.front() <= i - k - 1)
            {
                q.pop_front();
            }

            dp[i] = q.empty() ? nums[i] : max(dp[i], dp[q.front()] + nums[i]);
            while (q.size() > 0 && dp[q.back()] <= dp[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(void)
{
    Solution sol;
    vector<int> nums = {10, 2, -10, 5, 20};
    int k = 2;
    int res = sol.constrainedSubsetSum(nums, k);
    cout << res << endl;
    return 0;
}
