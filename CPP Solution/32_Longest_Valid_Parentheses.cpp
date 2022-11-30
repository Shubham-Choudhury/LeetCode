// Link: https://leetcode.com/problems/longest-valid-parentheses/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        int start = 0;
        stack<int> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else {
                if (stk.empty())
                    start = i + 1;
                else {
                    stk.pop();
                    if (stk.empty())
                        result = max(result, i - start + 1);
                    else
                        result = max(result, i - stk.top());
                }
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses(")()())") << endl;
    return 0;
}