// Link: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.size() == 0)
            return result;
        
        int wordLen = words[0].length();
        int totalLen = wordLen * words.size();
        if (s.length() < totalLen)
            return result;
        
        unordered_map<string, int> count;
        for (int i = 0; i < words.size(); i++)
            count[words[i]]++;
        
        for (int i = 0; i <= s.length() - totalLen; i++) {
            unordered_map<string, int> seen;
            int j = 0;
            for (; j < words.size(); j++) {
                string word = s.substr(i + j * wordLen, wordLen);
                if (count.find(word) == count.end())
                    break;
                seen[word]++;
                if (seen[word] > count[word])
                    break;
            }
            if (j == words.size())
                result.push_back(i);
        }
        
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "barfoothefoobarman";
    vector<string> words = { "foo", "bar" };
    vector<int> result = sol.findSubstring(s, words);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}