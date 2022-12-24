// Link: https://leetcode.com/problems/monotone-increasing-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string s = to_string(N);
        int n = s.size();
        int i = 1;
        while (i < n && s[i - 1] <= s[i]) {
            i++;
        }
        if (i < n) {
            while (i > 0 && s[i - 1] > s[i]) {
                s[i - 1]--;
                i--;
            }
            for (i++; i < n; i++) {
                s[i] = '9';
            }
        }
        return stoi(s);
    }
};

int main() {
    Solution s;
    int N;
    int ans;

    // Output: 1234
    N = 1234;
    ans = s.monotoneIncreasingDigits(N);
    cout << ans << endl;

    // Output: 299
    N = 332;
    ans = s.monotoneIncreasingDigits(N);
    cout << ans << endl;

    // Output: 9
    N = 10;
    ans = s.monotoneIncreasingDigits(N);
    cout << ans << endl;

    // Output: 999999999
    N = 999999999;
    ans = s.monotoneIncreasingDigits(N);
    cout << ans << endl;

    return 0;
}
