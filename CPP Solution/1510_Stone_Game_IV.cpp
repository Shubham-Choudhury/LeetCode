// Link: https://leetcode.com/problems/stone-game-iv/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main()
{
    Solution sol;
    int n;
    bool ans;

    // Output: true
    n = 1;
    ans = sol.winnerSquareGame(n);
    cout << ans << endl;

    // Output: false
    n = 2;
    ans = sol.winnerSquareGame(n);
    cout << ans << endl;

    // Output: true
    n = 4;
    ans = sol.winnerSquareGame(n);
    cout << ans << endl;

    // Output: false
    n = 7;
    ans = sol.winnerSquareGame(n);
    cout << ans << endl;

    // Output: false
    n = 17;
    ans = sol.winnerSquareGame(n);
    cout << ans << endl;

    return 0;
}
