// Link: https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        string result = "";
        for (string word : d) {
            int i = 0;
            for (char c : s) {
                if (i < word.length() && c == word[i])
                    i++;
            }
            if (i == word.length() && word.length() >= result.length()) {
                if (word.length() > result.length() || word < result)
                    result = word;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    string s = "abpcplea";
    vector<string> d = {"ale", "apple", "monkey", "plea"};
    cout << solution.findLongestWord(s, d) << endl;
    return 0;
}
