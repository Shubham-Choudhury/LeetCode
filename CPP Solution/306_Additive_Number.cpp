// Link: https://leetcode.com/problems/additive-number/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool isAdditiveNumber(string num)
    {

        if (num.size() < 3)
            return false;

        int len = num.length();
        for (int len1 = 1; len1 <= len; ++len1)
        {
            for (int len2 = 1; len2 <= len; ++len2)
            {

                if (len1 + len2 >= len)
                    continue;

                if (dfs(num, 0, len1, len2))
                    return true;
            }
        }

        return false;
    }

    bool dfs(string num, int s1, int l1, int l2)
    {

        if (s1 + l1 + l2 == num.length())
            return true;

        string str1 = num.substr(s1, l1);
        string str2 = num.substr(s1 + l1, l2);
        if ((str1.size() > 1 && str1[0] == '0') || (str2.size() > 1 && str2[0] == '0'))
            return false;

        long long v1 = atoll(str1.c_str());
        long long v2 = atoll(str2.c_str());
        long long v3 = v1 + v2;

        string str3 = to_string(v3);
        string target = num.substr(s1 + l1 + l2, str3.length());
        if (target == str3)
            return dfs(num, s1 + l1, l2, str3.length());
        else
            return false;
    }
};

int main()
{
    string num = "199100199";
    cout << Solution().isAdditiveNumber(num) << endl;
    return 0;
}
