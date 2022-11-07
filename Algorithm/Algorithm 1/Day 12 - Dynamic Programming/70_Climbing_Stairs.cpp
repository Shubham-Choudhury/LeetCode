// Link: https://leetcode.com/problems/climbing-stairs/?envType=study-plan&id=algorithm-i

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
    int n;
    cin >> n;
    Solution obj;
    cout << obj.climbStairs(n) << endl;
    return 0;
}