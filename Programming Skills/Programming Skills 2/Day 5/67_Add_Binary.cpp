// Link: https://leetcode.com/problems/add-binary/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry;
            if (i >= 0) {
                sum += a[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum += b[j] - '0';
                j--;
            }
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        if (carry != 0) {
            res = to_string(carry) + res;
        }
        return res;
    }
};

int main(){
    Solution s;
    string a = "11";
    string b = "1";
    cout << s.addBinary(a, b) << endl;
    return 0;
}