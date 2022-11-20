// Link: https://leetcode.com/problems/basic-calculator/

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0') {
                int num = 0;
                while (i < s.size() && s[i] >= '0') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                i--;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result = result * st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    cout << s.calculate("1 + 1") << endl;
    cout << s.calculate(" 2-1 + 2 ") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    return 0;
}