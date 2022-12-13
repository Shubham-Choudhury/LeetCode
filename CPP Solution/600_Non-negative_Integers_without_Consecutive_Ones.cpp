// Link: https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findIntegers(int num)
    {
        vector<int> dp(32, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i != 32; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        int ans = 0, k = 30, pre_bit = 0;
        while (k >= 0)
        {
            if (num & (1 << k))
            {
                ans += dp[k];
                if (pre_bit)
                    return ans;
                pre_bit = 1;
            }
            else
                pre_bit = 0;
            k--;
        }
        return ans + 1;
    }
};

int main()
{
    Solution obj;
    int num, res;

    num = 5;
    res = obj.findIntegers(num);
    cout << res << endl;

    num = 1;
    res = obj.findIntegers(num);
    cout << res << endl;

    return 0;
}