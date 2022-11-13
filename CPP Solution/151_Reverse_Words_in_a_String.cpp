// Link: https://leetcode.com/problems/reverse-words-in-a-string/

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        int j = 0;
        while (i < n) {
            while (i < n && s[i] == ' ') {
                i++;
            }
            if (i < n && j > 0) {
                s[j++] = ' ';
            }
            int start = j;
            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }
            reverse(s.begin() + start, s.begin() + j);
        }
        s.resize(j);
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(){
    Solution s;
    string str = "the sky is blue";
    cout << s.reverseWords(str) << endl;
    return 0;
}