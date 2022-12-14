// Link: https://leetcode.com/problems/guess-the-word/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Master
{
public:
    int guess(string word);
};

class Solution
{
public:
    int check(string &a, string &b)
    {
        int ct = 0;
        for (int i = 0; i < 6; i++)
            if (a[i] == b[i])
                ct++;
        return ct;
    }

    void findSecretWord(vector<string> &words, Master &master)
    {
        for (int i = 0, matches = 0; i < 30 and matches != 6; i++)
        {
            string trial = words[words.size() / 2];
            matches = master.guess(trial);
            vector<string> possibilities;
            for (auto word : words)
            {
                if (check(word, trial) == matches)
                    possibilities.push_back(word);
            }
            words = possibilities;
        }
    }
};

int main()
{
    Solution solution;
    return 0;
}
