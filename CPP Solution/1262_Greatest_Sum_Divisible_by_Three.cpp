// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(3, 0);
        for (int i = 0; i < n; i++)
        {
            vector<int> temp = dp;
            for (int j = 0; j < 3; j++)
            {
                dp[(temp[j] + nums[i]) % 3] = max(dp[(temp[j] + nums[i]) % 3], temp[j] + nums[i]);
            }
        }
        return dp[0];
    }
};

int main()
{
    Solution s;
    vector<int> nums = {3, 6, 5, 1, 8};
    cout << s.maxSumDivThree(nums) << endl;
    return 0;
}
