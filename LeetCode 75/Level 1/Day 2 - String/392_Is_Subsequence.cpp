// Link: https://leetcode.com/problems/is-subsequence/?envType=study-plan&id=level-1

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }
        return i == s.size();
    }
};

int main() {
    Solution s;
    string s1 = "abc";
    string t1 = "ahbgdc";
    cout << s.isSubsequence(s1, t1) << endl;
    string s2 = "axc";
    string t2 = "ahbgdc";
    cout << s.isSubsequence(s2, t2) << endl;
    return 0;
}