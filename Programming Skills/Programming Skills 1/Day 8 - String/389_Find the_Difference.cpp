// Link: https://leetcode.com/problems/find-the-difference/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.size();
        int m = t.size();
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < n; i++) {
            sum1 += s[i];
        }
        for(int i = 0; i < m; i++) {
            sum2 += t[i];
        }
        return (char)(sum2 - sum1);
    }
};

int main() {
    Solution s;
    cout << s.findTheDifference("abcd", "abcde") << endl;
    cout << s.findTheDifference("", "y") << endl;
    cout << s.findTheDifference("a", "aa") << endl;
    cout << s.findTheDifference("ae", "aea") << endl;
    return 0;
}