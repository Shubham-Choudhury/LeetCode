// Link: https://leetcode.com/problems/word-break-ii/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> memo;
        return helper(s, wordDict, memo);
    }
    
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& memo){
        if(memo.count(s)) return memo[s];
        if(s.empty()) return {""};
        vector<string> res;
        for(string word: wordDict){
            if(s.substr(0, word.size()) != word) continue;
            vector<string> rem = helper(s.substr(word.size()), wordDict, memo);
            for(string str: rem){
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        memo[s] = res;
        return res;
    }
};

int main() {
    Solution sol;
    string s;
    vector<string> wordDict;
    vector<string> result;
    
    s = "catsanddog";
    wordDict = {"cat", "cats", "and", "sand", "dog"};
    result = sol.wordBreak(s, wordDict);
    for (string str: result) {
        cout << str << endl;
    }
    
    s = "pineapplepenapple";
    wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
    result = sol.wordBreak(s, wordDict);
    for (string str: result) {
        cout << str << endl;
    }
    
    s = "catsandog";
    wordDict = {"cats", "dog", "sand", "and", "cat"};
    result = sol.wordBreak(s, wordDict);
    for (string str: result) {
        cout << str << endl;
    }
    
    s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    result = sol.wordBreak(s, wordDict);
    for (string str: result) {
        cout << str << endl;
    }
    
    return 0;
}
