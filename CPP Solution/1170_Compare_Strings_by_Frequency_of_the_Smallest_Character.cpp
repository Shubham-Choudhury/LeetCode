// Link: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
    {
        vector<int> res;
        vector<int> freq;
        for (auto word : words)
        {
            freq.emplace_back(frequency(word));
        }
        sort(freq.begin(), freq.end());
        for (auto query : queries)
        {
            int count = 0;
            int f = frequency(query);
            for (auto it : freq)
            {
                if (it > f)
                    count++;
            }
            res.emplace_back(count);
        }
        return res;
    }

    int frequency(string s)
    {
        int count = 0;
        char c = 'z';
        for (auto it : s)
        {
            if (it < c)
            {
                c = it;
                count = 1;
            }
            else if (it == c)
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    vector<string> queries = {"bbb", "cc"};
    vector<string> words = {"a", "aa", "aaa", "aaaa"};
    vector<int> res = s.numSmallerByFrequency(queries, words);
    for (auto it : res)
        cout << it << " ";
    return 0;
}
