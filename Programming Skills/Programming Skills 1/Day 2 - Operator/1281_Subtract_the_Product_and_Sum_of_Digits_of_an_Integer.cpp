// Link: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/?envType=study-plan&id=programming-skills-i

#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;
        while (n != 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n = n / 10;
        }
        return product - sum;
    }
};

int main() {
    Solution s;
    cout << s.subtractProductAndSum(234) << endl;
    cout << s.subtractProductAndSum(4421) << endl;
}