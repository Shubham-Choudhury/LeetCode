// Link: https://leetcode.com/problems/count-and-say/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1";
        for (int i = 1; i < n; ++i)
        {
            string tmp;
            int count = 1;
            for (int j = 1; j < res.size(); ++j)
            {
                if (res[j] == res[j - 1])
                    ++count;
                else
                {
                    tmp += to_string(count) + res[j - 1];
                    count = 1;
                }
            }
            tmp += to_string(count) + res.back();
            res = tmp;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(4) << endl;
    return 0;
}
