// Link: https://leetcode.com/problems/break-a-palindrome/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string breakPalindrome(string s) {
        int n = s.size();
        if (n == 1) return "";
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s[n - 1] = 'b';
        return s;
    }
};

int main() {
    Solution sol;
    string s = "abccba";
    cout << sol.breakPalindrome(s) << endl;
    return 0;
}
