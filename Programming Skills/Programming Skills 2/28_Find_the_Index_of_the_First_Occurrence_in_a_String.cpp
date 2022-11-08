// Link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int findFirstOccurrence(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        if (m > n) {
            return -1;
        }
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && s[i + j] == t[j]) {
                j++;
            }
            if (j == m) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string s = "hello";
    string t = "ll";
    cout << sol.findFirstOccurrence(s, t) << endl;
    return 0;
}