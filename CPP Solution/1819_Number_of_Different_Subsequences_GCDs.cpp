// Link: https://leetcode.com/problems/number-of-different-subsequences-gcds/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> dp(maxNum + 1, 0);
        for (int i = 0; i < n; i++)
        {
            dp[nums[i]] = 1;
        }
        int ans = 0;
        for (int i = 1; i <= maxNum; i++)
        {
            int gcd = 0;
            for (int j = i; j <= maxNum; j += i)
            {
                if (dp[j] == 1)
                {
                    gcd = __gcd(gcd, j);
                }
            }
            if (gcd == i)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {6, 10, 3};
    cout << s.countDifferentSubsequenceGCDs(nums) << endl;
    return 0;
}
