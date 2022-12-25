// Link: https://leetcode.com/problems/short-encoding-of-words/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        unordered_set<string> s(words.begin(), words.end());
        for (string word : words)
        {
            for (int i = 1; i < word.size(); i++)
            {
                s.erase(word.substr(i));
            }
        }
        int res = 0;
        for (string word : s)
        {
            res += word.size() + 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"time", "me", "bell"};
    cout << s.minimumLengthEncoding(words) << endl;
    return 0;
}
