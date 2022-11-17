// Link: https://leetcode.com/problems/repeated-dna-sequences/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> counter;
        vector<string> res;
        
        if (s.size() < 10) return res;
        
        for (int i=0; i<s.size()-9; i++)
            counter[s.substr(i, 10)]++;
        
        for (auto a:counter)
            if (a.second > 1)
                res.push_back(a.first);
        
        return res;
    }
};

int main() {
    Solution s;
    string S = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> result = s.findRepeatedDnaSequences(S);
    for (string sub : result) {
        cout << sub << endl;
    }
    return 0;
}