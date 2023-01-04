// Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string S)
    {
        stack<char> st;
        for (char c : S)
        {
            if (c == 'c')
            {
                if (st.empty() || st.top() != 'b')
                    return false;
                st.pop();
                if (st.empty() || st.top() != 'a')
                    return false;
                st.pop();
            }
            else
                st.push(c);
        }
        return st.empty();
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("aabcbc") << endl;
    cout << sol.isValid("abcabcababcc") << endl;
    cout << sol.isValid("abccba") << endl;
    cout << sol.isValid("cababc") << endl;
    return 0;
}
