// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && st.top() == c) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string s = "abbaca";
    solution sol;
    cout << sol.removeDuplicates(s) << endl;
    return 0;
}