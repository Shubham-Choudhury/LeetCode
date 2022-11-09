// Link: https://leetcode.com/problems/repeated-substring-pattern/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                bool flag = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution s;
    cout << s.repeatedSubstringPattern("abab") << endl;
    return 0;
}