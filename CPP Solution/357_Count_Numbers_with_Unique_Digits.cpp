// Link: https://leetcode.com/problems/count-numbers-with-unique-digits/

#include <iostream>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int res = 10, base = 9;
        for (int i = 2; i <= n; ++i) {
            base *= (9 - i + 2);
            res += base;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.countNumbersWithUniqueDigits(2) << endl;
    return 0;
}