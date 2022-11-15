// Link: https://leetcode.com/problems/word-pattern/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> m;
        unordered_map<string, char> m2;
        int i = 0;
        for (string word : split(str, ' ')) {
            if (i == pattern.size() || m.count(pattern[i]) && m[pattern[i]] != word || m2.count(word) && m2[word] != pattern[i]) {
                return false;
            }
            m[pattern[i]] = word;
            m2[word] = pattern[i];
            i++;
        }
        return i == pattern.size();
    }
    
    vector<string> split(string str, char c) {
        vector<string> result;
        int i = 0;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == c) {
                result.push_back(str.substr(i, j - i));
                i = j + 1;
            }
        }
        result.push_back(str.substr(i));
        return result;
    }
};

int main() {
    Solution s;
    cout << s.wordPattern("abba", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
    cout << s.wordPattern("aaaa", "dog cat cat dog") << endl;
    cout << s.wordPattern("abba", "dog dog dog dog") << endl;
    return 0;
}