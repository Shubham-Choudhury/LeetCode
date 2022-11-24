// Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(')
                st.push(i);
            else if(s[i] == ')') {
                if(!st.empty())
                    st.pop();
                else
                    s[i] = '*';
            }
        }
        while(!st.empty()) {
            s[st.top()] = '*';
            st.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};

int main() {
    Solution s;
    cout << s.minRemoveToMakeValid("lee(t(c)o)de)") << endl;
    return 0;
}