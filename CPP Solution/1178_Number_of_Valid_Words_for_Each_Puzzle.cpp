// Link: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
     int maskWord(string word) {
        int mask = 0;
        for (auto c : word) mask |= (1 << c-'a');
        return mask;
    }
    
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int, int> mask_freq;
        for (auto word : words) mask_freq[(maskWord(word))]++;
        
        vector<int> res;
        
        for (auto p : puzzles) {
            int mask = maskWord(p), submask = mask, first = (1 << p[0]-'a'), curr = 0;
            
            while (submask) {
                if (submask & first) curr += mask_freq[submask];
                
                submask = (submask-1) & mask;
            }
            
            res.push_back(curr);
        }
        return res;
    }

};

int main()
{
    Solution s;
    vector<string> words = {"aaaa", "asas", "able", "ability", "actt", "actor", "access"};
    vector<string> puzzles = {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"};
    vector<int> ans = s.findNumOfValidWords(words, puzzles);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
