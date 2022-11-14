// Link: https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution s;
    string str = "A man, a plan, a canal: Panama";
    bool result = s.isPalindrome(str);
    cout << result << endl;
    return 0;
}