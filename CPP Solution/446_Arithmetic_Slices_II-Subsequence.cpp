// Link: https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 3) return 0;
        int res = 0;
        vector<unordered_map<long long, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = (long long)A[i] - A[j];
                int sum = 0;
                if (dp[j].find(diff) != dp[j].end()) {
                    sum = dp[j][diff];
                }
                dp[i][diff] += sum + 1;
                res += sum;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> A = {2, 4, 6, 8, 10};
    cout << s.numberOfArithmeticSlices(A) << endl;
    return 0;
}