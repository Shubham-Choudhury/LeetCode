// Link: https://leetcode.com/problems/number-of-1-bits/?envType=study-plan&id=algorithm-i

#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if (n % 2 == 1) {
                count++;
            }
            n = n / 2;
        }
        return count;
    }
};

int main() {
    Solution sol;
    uint32_t n = 00000000000000000000000000001011;
    cout << sol.hammingWeight(n) << endl;
    return 0;
}
