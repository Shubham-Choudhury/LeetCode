// Link: https://leetcode.com/problems/number-of-music-playlists/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    int numMusicPlaylists(int N, int L, int K)
    {
        long long dp[L + 1][N + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= L; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                dp[i][j] = (dp[i - 1][j - 1] * (N - j + 1)) % 1000000007;
                if (j > K)
                {
                    dp[i][j] = (dp[i][j] + (dp[i - 1][j] * (j - K)) % 1000000007) % 1000000007;
                }
            }
        }

        return dp[L][N];
    }
};

int main()
{
    Solution s;
    cout << s.numMusicPlaylists(3, 3, 1) << endl;
    return 0;
}