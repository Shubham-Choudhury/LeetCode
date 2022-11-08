// Link: https://leetcode.com/problems/power-of-two/?envType=study-plan&id=algorithm-i

#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution sol;
    int n = 16;
    cout << sol.isPowerOfTwo(n) << endl;
    return 0;
}