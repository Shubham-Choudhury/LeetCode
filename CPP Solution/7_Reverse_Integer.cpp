// Link: https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        if(x < pow(-2, 31) || x > pow(2, 31) - 1)
            return 0;
        while (x != 0) {
            int tail = x % 10;
            int newResult = result * 10 + tail;
            if ((newResult - tail) / 10 != result)
                return 0;
            result = newResult;
            x = x / 10;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    int x = 123;
    cout << sol.reverse(x) << endl;
    return 0;
}
