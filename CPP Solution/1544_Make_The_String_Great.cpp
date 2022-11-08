// Link: https://leetcode.com/problems/make-the-string-great/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                if (abs(st.top() - s[i]) == 32) {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "leEeetcode";
    cout << sol.makeGood(s) << endl;
    return 0;
}