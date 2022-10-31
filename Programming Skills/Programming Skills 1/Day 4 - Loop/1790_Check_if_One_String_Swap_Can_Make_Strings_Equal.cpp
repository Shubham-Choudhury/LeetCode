// Link: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                count++;
            }
        }
        if (count > 2) {
            return false;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main() {
    Solution solution;
    string s1 = "bank";
    string s2 = "kanb";
    cout << solution.areAlmostEqual(s1, s2) << endl;
    return 0;
}