// Link: https://leetcode.com/problems/decode-string/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> strStack;
        string result;
        int count = 0;
        
        for (char c : s) {
            if (isdigit(c)) {
                count = count * 10 + c - '0';
            } else if (c == '[') {
                countStack.push(count);
                strStack.push(result);
                count = 0;
                result = "";
            } else if (c == ']') {
                string temp = result;
                for (int i = countStack.top() - 1; i > 0; i--) {
                    result += temp;
                }
                result = strStack.top() + result;
                countStack.pop();
                strStack.pop();
            } else {
                result += c;
            }
        }
        
        return result;
    }
};

int main(){
    Solution s;
    cout << s.decodeString("3[a]2[bc]") << endl;
    cout << s.decodeString("3[a2[c]]") << endl;
    cout << s.decodeString("2[abc]3[cd]ef") << endl;
    cout << s.decodeString("abc3[cd]xyz") << endl;
    return 0;
}