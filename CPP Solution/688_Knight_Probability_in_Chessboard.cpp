// Link: https://leetcode.com/problems/knight-probability-in-chessboard/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<double>> dp(N, vector<double>(N, 0));
        dp[r][c] = 1;
        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
        for (int k = 0; k < K; ++k) {
            vector<vector<double>> dp2(N, vector<double>(N, 0));
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    for (auto &dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < N && y >= 0 && y < N)
                            dp2[x][y] += dp[i][j] / 8.0;
                    }
                }
            }
            dp = dp2;
        }
        double res = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j)
                res += dp[i][j];
        }
        return res;
    }
};

int main()
{
    Solution obj;
    cout << obj.knightProbability(3, 2, 0, 0) << endl;
    return 0;
}
