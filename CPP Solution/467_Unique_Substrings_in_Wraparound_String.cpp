// Link: https://leetcode.com/problems/unique-substrings-in-wraparound-string/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.size();
        vector<int> dp(26, 0);
        int cur = 0;
        for (int i = 0; i < n; ++ i)
        {
            if (i > 0 && (p[i] - p[i - 1] == 1 || p[i - 1] - p[i] == 25))
                ++ cur;
            else
                cur = 1;
            dp[p[i] - 'a'] = max(dp[p[i] - 'a'], cur);
        }
        int res = 0;
        for (int i = 0; i < 26; ++ i)
            res += dp[i];
        return res;
    }
};

int main() {
    Solution sol;
    string p;
    int res;

    // Output: 6
    p = "a";
    res = sol.findSubstringInWraproundString(p);
    cout << res << endl;

    return 0;
}