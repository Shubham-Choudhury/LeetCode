// Link: https://leetcode.com/problems/edit-distance/?envType=study-plan&id=algorithm-ii

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i <= m; i++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
            }
        }
        return dp[m][n];
    }
};

int main() {
    Solution sol;
    string word1, word2;
    word1 = "horse";
    word2 = "ros";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}