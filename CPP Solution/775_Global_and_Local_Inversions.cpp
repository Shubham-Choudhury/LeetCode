// Link: https://leetcode.com/problems/global-and-local-inversions/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            if (abs(A[i] - i) > 1) {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> A;
    bool ans;

    // Output: true
    A = {1, 0, 2};
    ans = sol.isIdealPermutation(A);
    cout << ans << endl;

    // Output: false
    A = {1, 2, 0};
    ans = sol.isIdealPermutation(A);
    cout << ans << endl;

    return 0;
}
