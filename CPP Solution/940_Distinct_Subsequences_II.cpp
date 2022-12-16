// Link: https://leetcode.com/problems/distinct-subsequences-ii/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int distinctSubseqII(string S)
    {
        int n = S.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        int mod = 1e9 + 7;
        unordered_map<char, int> last;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (dp[i - 1] * 2) % mod;
            if (last.count(S[i - 1]))
            {
                dp[i] = (dp[i] - dp[last[S[i - 1]] - 1] + mod) % mod;
            }
            last[S[i - 1]] = i;
        }
        dp[n]--;
        if (dp[n] < 0)
            dp[n] += mod;
        return dp[n];
    }
};

int main()
{
    Solution a;
    cout << a.distinctSubseqII("abc") << endl;
    cout << a.distinctSubseqII("aba") << endl;
    cout << a.distinctSubseqII("aaa") << endl;
    return 0;
}
