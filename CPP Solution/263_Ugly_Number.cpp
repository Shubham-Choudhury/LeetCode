// Link: https://leetcode.com/problems/ugly-number/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        while (num % 2 == 0) {
            num /= 2;
        }
        while (num % 3 == 0) {
            num /= 3;
        }
        while (num % 5 == 0) {
            num /= 5;
        }
        return num == 1;
    }
};

int main() {
    Solution s;
    int num = 6;
    bool result = s.isUgly(num);
    cout << result << endl;
    return 0;
}