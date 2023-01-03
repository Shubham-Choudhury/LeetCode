// Link: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int n = s.size();
        int open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
            {
                if (open > 0)
                    open--;
                else
                    close++;
            }
        }
        return open + close;
    }
};

int main()
{
    Solution S;
    string s = "()))((";
    cout << S.minAddToMakeValid(s) << endl;
    return 0;
}
