// Link: https://leetcode.com/problems/construct-k-palindrome-strings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string s, int k)
    {
        int len = s.length();
        if (k > len)
            return false;
        if (k == len)
            return true;
        int count[26] = {0};
        for (int i = 0; i < len; i++)
        {
            count[s[i] - 'a']++;
        }
        int odd = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] % 2 != 0)
                odd++;
        }
        return odd <= k;
    }
};

int main()
{
    Solution s;
    string s = "annabelle";
    int k = 2;
    cout << s.canConstruct(s, k) << endl;
    return 0;
}