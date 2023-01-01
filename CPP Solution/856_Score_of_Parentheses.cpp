// Link: https://leetcode.com/problems/score-of-parentheses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scoreOfParentheses(string S)
    {
        int ans = 0;
        int bal = 0;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '(')
                bal++;
            else
            {
                bal--;
                if (S[i - 1] == '(')
                    ans += 1 << bal;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string S = "(()(()))";
    cout << s.scoreOfParentheses(S) << endl;
    return 0;
}
