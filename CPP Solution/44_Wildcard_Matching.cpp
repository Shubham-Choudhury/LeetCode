// Link: https://leetcode.com/problems/wildcard-matching/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, star = -1, match = 0;
        while (i < s.length()) {
            if (j < p.length() && (s[i] == p[j] || p[j] == '?')) {
                i++;
                j++;
            } else if (j < p.length() && p[j] == '*') {
                star = j;
                match = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        while (j < p.length() && p[j] == '*')
            j++;
        return j == p.length();
    }
};

int main() {
    Solution solution;
    cout << solution.isMatch("aa", "a") << endl;
    cout << solution.isMatch("aa", "*") << endl;
    cout << solution.isMatch("cb", "?a") << endl;
    cout << solution.isMatch("adceb", "*a*b") << endl;
    cout << solution.isMatch("acdcb", "a*c?b") << endl;
    return 0;
}