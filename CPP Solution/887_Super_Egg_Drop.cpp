// link: https://leetcode.com/problems/super-egg-drop/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));
        int m = 0;
        while (dp[K][m] < N) {
            m++;
            for (int k = 1; k <= K; k++) {
                dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
            }
        }
        return m;
    }
};

int main()
{
    Solution sol;
    int K;
    int N;

    // Output: 2
    K = 1, N = 2;
    cout << sol.superEggDrop(K, N) << endl;

    // Output: 3
    K = 2, N = 6;
    cout << sol.superEggDrop(K, N) << endl;

    // Output: 4
    K = 3, N = 14;
    cout << sol.superEggDrop(K, N) << endl;

    return 0;
}
