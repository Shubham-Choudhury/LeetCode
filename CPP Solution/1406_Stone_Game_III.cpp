// Link: https://leetcode.com/problems/stone-game-iii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int sum = 0;
            for (int j = i; j < i + 3 && j < n; ++j) {
                sum += stoneValue[j];
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }
        }
        if (dp[0] == 0) {
            return "Tie";
        }
        return dp[0] > 0 ? "Alice" : "Bob";
    }
};

int main(void) {
    Solution sol;
    vector<int> stoneValue = {1,2,3,7};
    string res = sol.stoneGameIII(stoneValue);
    cout << res << endl;
    return 0;
}
