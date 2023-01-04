// Link: https://leetcode.com/problems/camelcase-matching/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool match(string &pattern, string &word)
    {
        int i = 0, j = 0;
        while (i < pattern.size() && j < word.size())
        {
            if (pattern[i] == word[j])
            {
                i++;
                j++;
            }
            else if (isupper(word[j]))
                return false;
            else
                j++;
        }
        while (j < word.size())
        {
            if (isupper(word[j]))
                return false;
            j++;
        }
        return i == pattern.size();
    }
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        vector<bool> res;
        for (string &word : queries)
            res.push_back(match(pattern, word));
        return res;
    }
};

int main()
{
    Solution sol;
    vector<string> queries = {"FooBar", "FooBarTest", "FootBall", "FrameBuffer", "ForceFeedBack"};
    string pattern = "FB";
    vector<bool> res = sol.camelMatch(queries, pattern);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}
