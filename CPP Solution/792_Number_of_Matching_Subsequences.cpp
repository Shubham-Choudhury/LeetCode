// Link: https://leetcode.com/problems/number-of-matching-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numMatchingSubseq(string s, vector<string> &words)
    {
        vector<vector<int>> index(26);
        for (int i = 0; i < s.size(); ++i)
            index[s[i] - 'a'].push_back(i);
        int result = 0;
        for (auto &word : words)
        {
            int prev = -1;
            bool found = true;
            for (auto c : word)
            {
                auto it = upper_bound(index[c - 'a'].begin(), index[c - 'a'].end(), prev);
                if (it == index[c - 'a'].end())
                {
                    found = false;
                    break;
                }
                prev = *it;
            }
            if (found)
                ++result;
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s;
    vector<string> words;
    int result;

    // Output: 3
    s = "abcde";
    words = {"a", "bb", "acd", "ace"};
    result = sol.numMatchingSubseq(s, words);
    cout << result << endl;

    // Output: 2
    s = "dsahjpjauf";
    words = {"ahjpjau", "ja", "ahbwzgqnuk", "tnmlanowax"};
    result = sol.numMatchingSubseq(s, words);
    cout << result << endl;

    return 0;
}
