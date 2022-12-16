// Link: https://leetcode.com/problems/sum-of-subsequence-widths/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int n = A.size();
        long long res = 0;
        long long mod = 1e9 + 7;
        long long pow2 = 1;
        for (int i = 0; i < n; i++) {
            res = (res + (A[i] - A[n - i - 1]) * pow2) % mod;
            pow2 = pow2 * 2 % mod;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> A;

    // Output: 6
    A = {2, 1, 3};
    cout << sol.sumSubseqWidths(A) << endl;

    // Output: 10
    A = {2, 1, 3, 4};
    cout << sol.sumSubseqWidths(A) << endl;

    return 0;
}
