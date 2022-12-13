// Link: https://leetcode.com/problems/palindrome-pairs/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
    bool isPal(string& s, int start, int end) {
        while(start < end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        if(words.empty())
            return result;
        
        unordered_map<string, int> table;
        for(int i = 0; i < words.size(); i++) {
            table[words[i]]=i;
        }
        
        
        vector<int> r(2);
        for(int i = 0; i < words.size(); i++) {
            string cur = words[i];
            string prefix = cur;
            string suffix = cur ;
            int K = words[i].size();
            for(int l = 0; l <= K; l++) {
                if(isPal(prefix,0, l-1)) {
                    string tmp = cur.substr(l);
                    if(!tmp.empty())
                        reverse(tmp.begin(), tmp.end());
                    if(table.find(tmp) != table.end()) {
                            r[0] = table[tmp];
                            r[1] = i;
                            if((r[0] != r[1]) && (cur.size() >= words[r[0]].size()))
                                    result.push_back(r);
                        }
                    }
                if(isPal(suffix, l, K-1)) {
                        string tmp = cur.substr(0,l); 
                        reverse(tmp.begin(), tmp.end());
                        if(table.find(tmp) != table.end()) {
                            r[1] = table[tmp];
                            r[0] = i;
                            if((r[0] != r[1]) && (cur.size() > words[r[1]].size()))
                                    result.push_back(r);
                        }
                    }
                
                }
                
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> words;
    vector<vector<int>> res;
    
    // Output: [[0,1],[1,0]]
    words = {"bat", "tab", "cat"};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    // Output: [[0,1],[1,0],[3,2],[2,4]]
    words = {"abcd", "dcba", "lls", "s", "sssll"};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    // Output: [[0,1],[1,0]]
    words = {"a", ""};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    // Output: [[0,1],[1,0]]
    words = {"a", "abc", "aba", ""};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    // Output: [[0,1],[1,0],[2,4],[3,2],[4,3]]
    words = {"a", "b", "c", "ab", "ac", "aa"};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    // Output: [[0,1],[1,0],[2,4],[3,2],[4,3]]
    words = {"a", "b", "c", "aa", "ac", "aa"};
    res = sol.palindromePairs(words);
    for (auto &v: res) {
        for (auto &i: v)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}