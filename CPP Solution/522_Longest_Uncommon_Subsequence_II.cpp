// Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int result = -1;
        for(int i = 0; i < strs.size(); i++) {
            int j = 0;
            for(; j < strs.size(); j++) {
                if(i == j) continue;
                if(isSubsequence(strs[i], strs[j])) break;
            }
            if(j == strs.size()) result = max(result, (int)strs[i].size());
        }
        return result;
    }
    
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"aba", "cdc", "eae"};
    cout << s.findLUSlength(strs) << endl;
    return 0;
}
