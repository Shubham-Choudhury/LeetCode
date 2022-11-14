// Link: https://leetcode.com/problems/add-strings/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += num2[j] - '0';
                j--;
            }
            res = to_string(sum % 10) + res;
            carry = sum / 10;
        }
        return res;
    }
};

int main() {
    Solution sol;
    string num1 = "11";
    string num2 = "123";
    cout << sol.addStrings(num1, num2) << endl;
    return 0;
}