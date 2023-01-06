// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int res = 0;
        vector<int> dp = {0};
        for (string s : arr)
        {
            int mask = 0;
            for (char c : s)
            {
                int bit = c - 'a';
                if ((mask >> bit) & 1)
                {
                    mask = 0;
                    break;
                }
                mask |= 1 << bit;
            }
            if (mask == 0)
                continue;
            for (int i = dp.size() - 1; i >= 0; i--)
            {
                if ((dp[i] & mask) == 0)
                    dp.push_back(dp[i] | mask);
            }
        }
        for (int i = 0; i < dp.size(); i++)
            res = max(res, __builtin_popcount(dp[i]));
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> arr = {"un", "iq", "ue"};
    cout << s.maxLength(arr) << endl;
    return 0;
}
