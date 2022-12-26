// Link: https://leetcode.com/problems/masking-personal-information/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maskPII(string S)
    {
        string res = "", str = "";
        for (char c : S)
        {
            if (c >= 'a' && c <= 'z')
                str.push_back(c);
            else if (c >= 'A' && c <= 'Z')
                str.push_back(c + 32);
            else if (c >= '0' && c <= '9')
                str.push_back(c);
            else if (c == '@')
            {
                res += string(1, str[0]) + "*****" + string(1, str.back()) + "@";
                str.clear();
            }
            else if (c == '.')
            {
                res += str + ".";
                str.clear();
            }
        }
        if (!res.empty())
            return res + str;
        if (str.size() > 10)
        {
            res += "+" + string(str.size() - 10, '*') + "-***-***-" + str.substr(str.size() - 4);
        }
        else
        {
            res += "***-***-" + str.substr(6);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.maskPII("LeetCode@LeetCode.com") << endl;
    return 0;
}