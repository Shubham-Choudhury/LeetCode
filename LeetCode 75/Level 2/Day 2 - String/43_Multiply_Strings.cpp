// Link: https://leetcode.com/problems/multiply-strings/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        if (n1 == 0 || n2 == 0) {
            return "";
        }
        
        vector<int> result(n1 + n2, 0);
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j] += sum / 10;
                result[i + j + 1] = sum % 10;
            }
        }
        
        string str = "";
        for (int i = 0; i < n1 + n2; i++) {
            if (str.empty() && result[i] == 0) {
                continue;
            }
            str += to_string(result[i]);
        }
        
        return str.empty() ? "0" : str;
    }
};

int main() {
    Solution sol;
    string num1, num2, result;
    
    num1 = "2";
    num2 = "3";
    result = sol.multiply(num1, num2);
    cout << result << endl;
    
    num1 = "123";
    num2 = "456";
    result = sol.multiply(num1, num2);
    cout << result << endl;
    
    return 0;
}