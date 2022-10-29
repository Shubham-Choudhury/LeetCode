// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INT_MAX = 2147483647;
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) {
            return -1;
        }
        vector<vector<int>> dp(d, vector<int>(n));
        dp[0][0] = jobDifficulty[0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[0][i - 1], jobDifficulty[i]);
        }
        for (int i = 1; i < d; i++) {
            for (int j = i; j < n; j++) {
                int maxDifficulty = jobDifficulty[j];
                dp[i][j] = INT_MAX;
                for (int k = j; k >= i; k--) {
                    maxDifficulty = max(maxDifficulty, jobDifficulty[k]);
                    dp[i][j] = min(dp[i][j], dp[i - 1][k - 1] + maxDifficulty);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};

int main() {
    Solution s;
    vector<int> jobDifficulty = {9,9,9};
    cout << s.minDifficulty(jobDifficulty, 4) << endl;
    return 0;
}

