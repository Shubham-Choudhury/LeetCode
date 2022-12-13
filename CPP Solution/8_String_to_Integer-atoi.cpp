// Link: https://leetcode.com/problems/string-to-integer-atoi/

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0, n = str.size();
        while (i != n && str[i] == ' ')
            i++;
        if (i == n)
            return 0;
        int sign = 1;
        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (str[i] == '+')
            i++;
        long long res = 0;
        while (i != n && str[i] >= '0' && str[i] <= '9')
        {
            res = res * 10 + str[i] - '0';
            if (res * sign > INT_MAX)
                return INT_MAX;
            if (res * sign < INT_MIN)
                return INT_MIN;
            i++;
        }
        return res * sign;
    }
};

int main()
{
    Solution obj;
    string str;
    int res;

    str = "42";
    res = obj.myAtoi(str);
    cout << res << endl;

    str = "   -42";
    res = obj.myAtoi(str);
    cout << res << endl;

    str = "4193 with words";
    res = obj.myAtoi(str);
    cout << res << endl;

    str = "words and 987";
    res = obj.myAtoi(str);
    cout << res << endl;

    str = "-91283472332";
    res = obj.myAtoi(str);
    cout << res << endl;

    return 0;
}
