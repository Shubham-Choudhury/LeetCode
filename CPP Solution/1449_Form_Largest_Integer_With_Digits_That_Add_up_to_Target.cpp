// Link: https://leetcode.com/problems/form-largest-integer-with-digits-that-add-up-to-target/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
    inline bool isGreaterThan(string &a, string &b)
    {
        return a.size() != b.size() ? a.size() > b.size() : a > b;
    }

public:
    string largestNumber(vector<int> &A, int T)
    {
        int N = A.size();
        vector<vector<string>> dp(N + 1, vector<string>(T + 1, "0"));
        for (int i = 0; i <= N; ++i)
            dp[i][0] = "";
        for (int i = 0; i < N; ++i)
        {
            for (int c = 1; c <= T; ++c)
            {
                dp[i + 1][c] = dp[i][c];
                if (c < A[i] || dp[i + 1][c - A[i]] == "0")
                    continue;
                auto s = string(1, '1' + i) + dp[i + 1][c - A[i]];
                if (isGreaterThan(s, dp[i + 1][c]))
                    dp[i + 1][c] = s;
            }
        }
        return dp[N][T];
    }
};

int main(void)
{
    Solution sol;
    vector<int> cost = {4, 3, 2, 5, 6, 7, 2, 5, 5};
    int target = 9;
    string res = sol.largestNumber(cost, target);
    cout << res << endl;
    return 0;
}
