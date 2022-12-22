// Link: https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/

#include <iostream>
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        long long mod = 1e9 + 7;
        long long abc = 6, abd = 6;
        for (int i = 1; i < n; ++i) {
            long long abc2 = (abc * 2 + abd * 2) % mod;
            long long abd2 = (abc * 2 + abd * 3) % mod;
            abc = abc2;
            abd = abd2;
        }
        return (abc + abd) % mod;
    }
};

int main(void) {
    Solution sol;
    int n = 1;
    int res = sol.numOfWays(n);
    cout << res << endl;
    return 0;
}
