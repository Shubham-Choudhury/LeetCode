// Link: https://leetcode.com/problems/odd-even-jump/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <map>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& A) {
        int n = A.size();
        vector<int> odd_next(n, -1), even_next(n, -1);
        map<int, int> num_idx;
        for (int i = n-1; i >= 0; i--) {
            auto it = num_idx.lower_bound(A[i]);
            if (it != num_idx.end()) {
                odd_next[i] = it->second;
            }
            it = num_idx.upper_bound(A[i]);
            if (it != num_idx.begin() && --it != num_idx.end()) {
                even_next[i] = it->second;
            }
            num_idx[A[i]] = i;
        }
        vector<bool> odd(n, false), even(n, false);
        odd[n-1] = even[n-1] = true;
        int res = 1;
        for (int i = n-2; i >= 0; i--) {
            if (odd_next[i] != -1) {
                odd[i] = even[odd_next[i]];
            }
            if (even_next[i] != -1) {
                even[i] = odd[even_next[i]];
            }
            if (odd[i]) {
                res++;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> A = {10, 13, 12, 14, 15};
    cout << sol.oddEvenJumps(A) << endl;
    return 0;
}
