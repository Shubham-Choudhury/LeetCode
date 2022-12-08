// Link: https://leetcode.com/problems/burst-balloons/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    typedef long long int i64;

    vector<int> myNums;
    int nlen;
    vector<vector<i64>> dp;

public:
    int maxCoins(vector<int> &nums)
    {
        myNums = nums;
        nlen = myNums.size();
        dp = vector<vector<i64>>(nlen, vector<i64>(nlen, -1));
        return maxCoins(0, nlen - 1);
    }

    i64 maxCoins(int left, int right)
    {
        if (left > right)
            return 0;
        if (dp[left][right] != -1)
            return dp[left][right];

        i64 res = 0;
        for (int i = left; i <= right; ++i)
        {
            i64 l = maxCoins(left, i - 1);
            i64 r = maxCoins(i + 1, right);
            i64 v = (left == 0 ? 1 : myNums[left - 1]) * myNums[i] * (right == nlen - 1 ? 1 : myNums[right + 1]);
            res = max(res, l + r + v);
        }
        dp[left][right] = res;
        return res;
    }
};

int main()
{
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;
    cout << sol.maxCoins(nums) << endl;

    return 0;
}
