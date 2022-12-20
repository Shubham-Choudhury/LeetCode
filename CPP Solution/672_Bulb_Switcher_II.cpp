// Link: https://leetcode.com/problems/bulb-switcher-ii/

#include <iostream>
using namespace std;

class Solution {
public:
    int flipLights(int n, int m) {
        if (n == 0 || m == 0) {
            return 1;
        }
        if (n == 1) {
            return 2;
        }
        if (n == 2) {
            return m == 1 ? 3 : 4;
        }
        return m == 1 ? 4 : m == 2 ? 7 : 8;
    }
};

int main(void) {
    Solution sol;
    int n = 3, m = 1;
    int res = sol.flipLights(n, m);
    cout << res << endl;
    return 0;
}
