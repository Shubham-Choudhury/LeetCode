// Link: https://leetcode.com/problems/reverse-integer/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) return 0;
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) return 0;
            ans = ans * 10 + digit;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int x = 123;
    cout << sol.reverse(x) << endl;
    return 0;
}
