// Link: https://leetcode.com/problems/maximum-product-of-word-lengths/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> masks(words.size(), 0);
        for (int i = 0; i < words.size(); ++i)
        {
            for (char c : words[i])
            {
                masks[i] |= 1 << (c - 'a');
            }
        }
        int result = 0;
        for (int i = 0; i < words.size(); ++i)
        {
            for (int j = i + 1; j < words.size(); ++j)
            {
                if ((masks[i] & masks[j]) == 0)
                {
                    result = max(result, static_cast<int>(words[i].size() * words[j].size()));
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
    cout << solution.maxProduct(words) << endl;
    return 0;
}
