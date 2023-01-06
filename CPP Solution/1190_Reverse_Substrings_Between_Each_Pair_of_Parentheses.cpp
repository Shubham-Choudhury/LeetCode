// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                reverse(s.begin() + st.top() + 1, s.begin() + i);
                st.pop();
            }
        }
        string res;
        for (auto c : s)
            if (c != '(' && c != ')')
                res += c;
        return res;
    }
};

int main()
{
    Solution s;
    string s1 = "(abcd)";
    cout << s.reverseParentheses(s1);
    return 0;
}
