// Link: https://leetcode.com/problems/valid-parentheses/?envType=study-plan&id=data-structure-i

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if(st.empty()) {
                    return false;
                }
                char top = st.top();
                st.pop();
                if(s[i] == ')' && top != '(') {
                    return false;
                }
                if(s[i] == ']' && top != '[') {
                    return false;
                }
                if(s[i] == '}' && top != '{') {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    return 0;
}