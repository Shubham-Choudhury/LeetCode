// Link: https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan&id=dynamic-programming-i

#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int a = 0;
        int b = 1;
        int c = 1;
        int d = 0;
        for (int i = 3; i <= n; i++) {
            d = a + b + c;
            a = b;
            b = c;
            c = d;
        }
        return d;
    }
};

int main() {
    Solution s;
    cout << s.tribonacci(0) << endl;
    cout << s.tribonacci(1) << endl;
    cout << s.tribonacci(2) << endl;
    cout << s.tribonacci(3) << endl;
    cout << s.tribonacci(4) << endl;
}