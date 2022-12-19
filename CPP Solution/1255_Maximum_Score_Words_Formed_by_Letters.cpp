// Link: https://leetcode.com/problems/maximum-score-words-formed-by-letters/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int wn = words.size();
        int total = 1 << wn;
        int res = 0;
        sort(letters.begin(), letters.end());
        for (int i = 0; i < total; ++i)
        {
            int ci = i, index = 0;
            string s;
            while (ci > 0)
            {
                if (ci & 1)
                    s += words[index];
                ci >>= 1;
                index++;
            }
            sort(s.begin(), s.end());
            string setres;
            set_union(s.begin(), s.end(), letters.begin(), letters.end(), back_inserter(setres));
            if (setres.size() > letters.size())
                continue;
            int value = 0;
            for (char c : s)
            {
                value += score[c - 'a'];
            }
            res = max(value, res);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> words = {"dog", "cat", "dad", "good"};
    vector<char> letters = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    cout << s.maxScoreWords(words, letters, score) << endl;
    return 0;
}
