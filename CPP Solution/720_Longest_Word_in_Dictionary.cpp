// Link: https://leetcode.com/problems/longest-word-in-dictionary/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> s;
        string res;
        for (string word : words)
        {
            if (word.size() == 1 || s.count(word.substr(0, word.size() - 1)))
            {
                res = word.size() > res.size() ? word : res;
                s.insert(word);
            }
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<string> words = {"w", "wo", "wor", "worl", "world"};
    cout << obj.longestWord(words) << endl;
    return 0;
}
