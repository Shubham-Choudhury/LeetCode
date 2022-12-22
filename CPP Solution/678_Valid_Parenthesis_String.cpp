// Link: https://leetcode.com/problems/valid-parenthesis-string/

#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkValidString(string s)
    {
        int lo = 0, hi = 0;
        for (char c : s)
        {
            lo += c == '(' ? 1 : -1;
            hi += c != ')' ? 1 : -1;
            if (hi < 0)
                break;
            lo = max(lo, 0);
        }
        return lo == 0;
    }
};

int main()
{
    Solution obj;
    cout << obj.checkValidString("()") << endl;
    cout << obj.checkValidString("(*)") << endl;
    cout << obj.checkValidString("(*))") << endl;
    return 0;
}
