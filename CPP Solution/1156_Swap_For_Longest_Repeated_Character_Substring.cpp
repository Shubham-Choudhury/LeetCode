// Link: https://leetcode.com/problems/swap-for-longest-repeated-character-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxRepOpt1(string str, int res = 0)
    {
        for (auto ch = 'a'; ch <= 'z'; ++ch)
        {
            int i = 0, j = 0, gap = 0;
            while (i < str.size())
            {
                gap += str[i++] != ch;
                if (gap > 1)
                    gap -= str[j++] != ch;
            }
            res = max(res, min(i - j, (int)count_if(begin(str), end(str), [&](char ch1)
                                                    { return ch1 == ch; })));
        }
        return res;
    }
};

int main()
{
    Solution s;
    string text = "ababa";
    cout << s.maxRepOpt1(text);
    return 0;
}
