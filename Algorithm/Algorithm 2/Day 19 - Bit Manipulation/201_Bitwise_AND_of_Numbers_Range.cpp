// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=study-plan&id=algorithm-ii

#include <iostream>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if ((m & (1 << i)) != (n & (1 << i)))
                break;
            res |= (m & (1 << i));
        }
        return res;
    }
};

int main() {
    Solution obj;
    cout << obj.rangeBitwiseAnd(5, 7);
    return 0;
}