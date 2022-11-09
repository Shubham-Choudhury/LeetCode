// Link: https://leetcode.com/problems/reverse-bits/?envType=study-plan&id=algorithm-i

#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) + (n & 1);
            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution s;
    uint32_t n = 43261596;
    cout << s.reverseBits(n) << endl;
    return 0;
}