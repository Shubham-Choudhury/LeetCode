// Link: https://leetcode.com/problems/fibonacci-number/?envType=study-plan&id=level-1

#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        if (N == 1) {
            return 1;
        }
        int a = 0;
        int b = 1;
        int c = 0;
        for (int i = 2; i <= N; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.fib(4) << endl;
    return 0;
}
