// Link: https://leetcode.com/problems/largest-palindrome-product/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int upper = pow(10, n) - 1;
        int lower = upper / 10;
        for (int i = upper; i > lower; i--) {
            long palindrome = buildPalindrome(i);
            for (long j = upper; j * j > palindrome; j--) {
                if (palindrome % j == 0) {
                    return palindrome % 1337;
                }
            }
        }
        return -1;
    }
    
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
};

int main() {
    Solution s;
    int n = 2;
    cout << s.largestPalindrome(n) << endl;
    return 0;
}