// Link: https://leetcode.com/problems/find-and-replace-pattern/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern)
    {
        vector<string> ans;
        for (auto word : words)
        {
            if (isMatch(word, pattern))
            {
                ans.push_back(word);
            }
        }
        return ans;
    }

    bool isMatch(string word, string pattern)
    {
        unordered_map<char, char> m;
        unordered_set<char> s;
        for (int i = 0; i < word.size(); i++)
        {
            if (m.find(word[i]) == m.end())
            {
                if (s.find(pattern[i]) != s.end())
                {
                    return false;
                }
                m[word[i]] = pattern[i];
                s.insert(pattern[i]);
            }
            else
            {
                if (m[word[i]] != pattern[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> ans = s.findAndReplacePattern(words, pattern);
    for (auto word : ans)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
