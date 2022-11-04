// Link: https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0;
        int j = s.length() - 1;
        while (i < j) {
            while (i < j && !isVowel(s[i])) {
                i++;
            }
            while (i < j && !isVowel(s[j])) {
                j--;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
    
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("hello") << endl;
    cout << s.reverseVowels("leetcode") << endl;
    cout << s.reverseVowels("aA") << endl;
    return 0;
}