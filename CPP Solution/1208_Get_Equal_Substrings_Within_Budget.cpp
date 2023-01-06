// Link: https://leetcode.com/problems/get-equal-substrings-within-budget/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.size(), res = 0, sum = 0;
        for (int i = 0, j = 0; i < n; i++)
        {
            sum += abs(s[i] - t[i]);
            while (sum > maxCost)
                sum -= abs(s[j] - t[j++]);
            res = max(res, i - j + 1);
        }
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "abcd", t1 = "bcdf";
    int maxCost1 = 3;
    cout << s.equalSubstring(s1, t1, maxCost1);
    return 0;
}
