// Link: https://leetcode.com/problems/triples-with-bitwise-and-equal-to-zero/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& A) {
        int n = A.size();
        vector<int> dp(1 << 16, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[A[i] & A[j]]++;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < (1 << 16); j++) {
                if ((A[i] & j) == 0) {
                    res += dp[j];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A = {2, 1, 3};
    cout << sol.countTriplets(A) << endl;
    return 0;
}
