// Link: https://leetcode.com/problems/number-of-digit-one/

#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            res += (n / divider) * i + min(max(n % divider - i + 1, 0LL), i);
        }
        return res;
    }
};

int main() {
    int n = 13;
    Solution sol;
    cout << sol.countDigitOne(n) << endl;
    
    return 0;
}
