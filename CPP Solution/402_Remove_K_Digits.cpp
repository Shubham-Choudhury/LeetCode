// Link: https://leetcode.com/problems/remove-k-digits/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (k == num.size())
            return "0";
        string result = "";
        int i = 0;
        while (i < num.size())
        {
            while (k > 0 && result.size() > 0 && result.back() > num[i])
            {
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
            i++;
        }
        while (k > 0)
        {
            result.pop_back();
            k--;
        }
        i = 0;
        while (i < result.size() && result[i] == '0')
            i++;
        if (i == result.size())
            return "0";
        return result.substr(i);
    }
};

int main()
{
    Solution s;
    cout << s.removeKdigits("1432219", 3) << endl;
    return 0;
}
