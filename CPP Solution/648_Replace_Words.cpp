// Link: https://leetcode.com/problems/replace-words/

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        string ans = "";
        unordered_set<string> dict;
        for (auto word : dictionary)
        {
            dict.insert(word);
        }
        stringstream ss(sentence);
        string word;
        while (ss >> word)
        {
            string prefix = "";
            for (int i = 0; i < word.size(); ++i)
            {
                prefix += word[i];
                if (dict.count(prefix))
                {
                    word = prefix;
                    break;
                }
            }
            ans += word + " ";
        }
        ans.pop_back();
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> dict = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << s.replaceWords(dict, sentence) << endl;
    return 0;
}
