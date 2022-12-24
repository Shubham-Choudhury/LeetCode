// Link: https://leetcode.com/problems/swap-adjacent-in-lr-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canTransform(string start, string end)
    {
        if (start.length() != end.length())
            return 0;
        int count = 0;
        for (int i = 0; i < start.length(); i++)
        {
            if (start[i] == 'R')
            {
                count++;
            }
            if (end[i] == 'R')
            {
                if (--count < 0)
                    return 0;
            }
            else if (end[i] == 'L' && count != 0)
                return 0;
        }
        if (count != 0)
            return 0;
        for (int i = start.size(); i >= 0; i--)
        {
            if (start[i] == 'L')
                count++;
            if (end[i] == 'L')
            {
                if (--count < 0)
                    return 0;
            }
            else if (end[i] == 'R' && count != 0)
                return 0;
        }
        return count == 0;
    }
};

int main()
{
    Solution sol;
    string start;
    string end;
    bool ans;

    // Output: true
    start = "RXXLRXRXL";
    end = "XRLXXRRLX";
    ans = sol.canTransform(start, end);
    cout << ans << endl;

    // Output: false
    start = "X";
    end = "L";
    ans = sol.canTransform(start, end);
    cout << ans << endl;

    // Output: false
    start = "LLR";
    end = "RRL";
    ans = sol.canTransform(start, end);
    cout << ans << endl;

    // Output: false
    start = "XL";
    end = "LX";
    ans = sol.canTransform(start, end);
    cout << ans << endl;

    // Output: true
    start = "XLLR";
    end = "LXLX";
    ans = sol.canTransform(start, end);
    cout << ans << endl;

    return 0;
}
