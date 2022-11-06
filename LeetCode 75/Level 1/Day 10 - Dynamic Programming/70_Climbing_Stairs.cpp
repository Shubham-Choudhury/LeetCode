// Link: https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=level-1

#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int a = 1;
        int b = 2;
        int c = 0;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.climbStairs(4) << endl;
    return 0;
}