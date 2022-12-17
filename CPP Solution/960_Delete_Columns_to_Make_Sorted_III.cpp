// Link: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int m = A[0].size();
        vector<int> dp(m, 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                bool ok = true;
                for (int k = 0; k < n; k++) {
                    if (A[k][j] > A[k][i]) {
                        ok = false;
                        break;
                    }
                }
                if (ok) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return m - *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<string> A = {"babca", "bbazb"};
    cout << sol.minDeletionSize(A) << endl;
    return 0;
}
