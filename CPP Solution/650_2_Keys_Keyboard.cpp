// Link: https://leetcode.com/problems/2-keys-keyboard/

#include <iostream>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int ans = 0;
        for (int i = 2; i <= n; ++i) {
            while (n % i == 0) {
                ans += i;
                n /= i;
            }
        }
        return ans;
    }
};

int main(void) {
    Solution sol;
    int n = 3;
    int res = sol.minSteps(n);
    cout << res << endl;
    return 0;
}
