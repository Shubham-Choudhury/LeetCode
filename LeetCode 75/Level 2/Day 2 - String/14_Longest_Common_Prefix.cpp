// Link: https://leetcode.com/problems/longest-common-prefix/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) {
            return "";
        }
        
        string prefix = strs[0];
        for (int i = 1; i < n; i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) {
                    return "";
                }
            }
        }
        
        return prefix;
    }
};

int main() {
    Solution sol;
    vector<string> strs;
    string result;
    
    strs = {"flower","flow","flight"};
    result = sol.longestCommonPrefix(strs);
    cout << result << endl;
    
    strs = {"dog","racecar","car"};
    result = sol.longestCommonPrefix(strs);
    cout << result << endl;
    
    return 0;
}