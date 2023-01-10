// Link: https://leetcode.com/problems/four-divisors/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumFourDivisors(vector<int> &nums)
    {
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 0;
            int sum = 0;
            for (int j = 1; j <= sqrt(nums[i]); j++)
            {
                if (nums[i] % j == 0)
                {
                    if (nums[i] / j == j)
                    {
                        count++;
                        sum += j;
                    }
                    else
                    {
                        count += 2;
                        sum += j + nums[i] / j;
                    }
                }
            }
            if (count == 4)
                res += sum;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {21, 4, 7};
    int ans = sol.sumFourDivisors(nums);
    cout << ans << endl;
    return 0;
}