// Link: https://leetcode.com/problems/number-of-1-bits/?envType=study-plan&id=programming-skills-i

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
    Solution s;
    cout << s.hammingWeight(00000000000000000000000000001011) << endl;
    cout << s.hammingWeight(00000000000000000000000010000000) << endl;
    cout << s.hammingWeight(11111111111111111111111111111101) << endl;
}