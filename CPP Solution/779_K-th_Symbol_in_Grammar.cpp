// Link: https://leetcode.com/problems/k-th-symbol-in-grammar/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) {
            return 0;
        }
        int parent = kthGrammar(N - 1, (K + 1) / 2);
        if (parent == 0) {
            return K % 2 == 0 ? 1 : 0;
        } else {
            return K % 2 == 0 ? 0 : 1;
        }
    }
};

int main()
{
    Solution sol;
    int N, K;
    int ans;

    // Output: 0
    N = 1, K = 1;
    ans = sol.kthGrammar(N, K);
    cout << ans << endl;

    // Output: 0
    N = 2, K = 1;
    ans = sol.kthGrammar(N, K);
    cout << ans << endl;

    // Output: 1
    N = 2, K = 2;
    ans = sol.kthGrammar(N, K);
    cout << ans << endl;

    // Output: 1
    N = 4, K = 5;
    ans = sol.kthGrammar(N, K);
    cout << ans << endl;

    return 0;
}
