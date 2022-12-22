// Link: https://leetcode.com/problems/restore-the-array/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int numberOfArrays(string s, int k) {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '0') {
                continue;
            }
            long long sum = 0;
            for (int j = i; j < n; ++j) {
                sum = sum * 10 + s[j] - '0';
                if (sum > k) {
                    break;
                }
                dp[i] = (dp[i] + dp[j + 1]) % 1000000007;
            }
        }
        return dp[0];
    }
};

int main(void) {
    Solution sol;
    string s = "1000";
    int k = 10000;
    int res = sol.numberOfArrays(s, k);
    cout << res << endl;
    return 0;
}
