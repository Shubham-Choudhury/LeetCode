// Link: https://leetcode.com/problems/add-digits/

#include <iostream>
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main() {
    Solution s;
    int num = 38;
    int result = s.addDigits(num);
    cout << result << endl;
    return 0;
}