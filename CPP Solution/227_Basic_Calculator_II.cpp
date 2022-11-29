// Link: https://leetcode.com/problems/basic-calculator-ii/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp * num);
                } else if (sign == '/') {
                    int temp = st.top();
                    st.pop();
                    st.push(temp / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main() {
    solution obj;
    string s = "3+2*2";
    cout << obj.calculate(s);
    return 0;
}