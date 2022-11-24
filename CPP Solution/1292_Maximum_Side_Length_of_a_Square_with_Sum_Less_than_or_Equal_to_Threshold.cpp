// Link: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        int low = 0, high = min(n, m);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            bool found = false;
            for (int i = mid; i <= n; i++) {
                for (int j = mid; j <= m; j++) {
                    int sum = dp[i][j] - dp[i - mid][j] - dp[i][j - mid] + dp[i - mid][j - mid];
                    if (sum <= threshold) {
                        found = true;
                        break;
                    }
                }
                if (found)
                    break;
            }
            if (found)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
    cout << s.maxSideLength(mat, 4);
    return 0;
}