// Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            } else {
                if (bit_a == 0 && bit_b == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int a = 2, b = 6, c = 5;
    cout << sol.minFlips(a, b, c) << endl;
    return 0;
}
