// Link: https://leetcode.com/problems/shortest-palindrome/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (s[i] == s[j]) i++;
        }
        if (i == n) return s;
        string remain_rev = s.substr(i, n - i);
        reverse(remain_rev.begin(), remain_rev.end());
        return remain_rev + shortestPalindrome(s.substr(0, i)) + s.substr(i, n - i);
    }
};

int main() {
    string s = "aacecaaa";
    Solution sol;
    cout << sol.shortestPalindrome(s) << endl;
    
    return 0;
}