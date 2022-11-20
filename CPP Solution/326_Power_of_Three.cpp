// Link: https://leetcode.com/problems/power-of-three/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) {
            return false;
        }
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1;
    }
};

int main() {
    Solution s;
    cout << s.isPowerOfThree(27) << endl;
    return 0;
}