// Link: https://leetcode.com/problems/longest-string-chain/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int res = 0;
        for (auto &word : words)
        {
            int best = 0;
            for (int i = 0; i < word.size(); i++)
            {
                string prev = word.substr(0, i) + word.substr(i + 1);
                best = max(best, dp[prev] + 1);
            }
            dp[word] = best;
            res = max(res, best);
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << sol.longestStrChain(words) << endl;
    return 0;
}
