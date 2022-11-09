// Link: https://leetcode.com/problems/word-ladder/?envType=study-plan&id=graph-i

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        
        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string curr = q.front();
                q.pop();
                
                if (curr == endWord)
                    return level;
                
                for (int j = 0; j < curr.size(); j++) {
                    char old = curr[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        curr[j] = c;
                        if (wordSet.find(curr) != wordSet.end() && visited.find(curr) == visited.end()) {
                            q.push(curr);
                            visited.insert(curr);
                        }
                    }
                    curr[j] = old;
                }
            }
            level++;
        }
        
        return 0;
    }

};

int main()
{
    Solution s;
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout << s.ladderLength("hit", "cog", wordList) << endl;
    return 0;
}

