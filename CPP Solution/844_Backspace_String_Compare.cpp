// Link: https://leetcode.com/problems/backspace-string-compare/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int i = S.length() - 1;
        int j = T.length() - 1;
        int skipS = 0;
        int skipT = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                if (S[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (T[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            if (i >= 0 && j >= 0 && S[i] != T[j]) {
                return false;
            }
            
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            
            i--;
            j--;
        }
        
        return true;
    }
};

int main(){
    Solution s;
    cout << s.backspaceCompare("ab#c", "ad#c") << endl;
    cout << s.backspaceCompare("ab##", "c#d#") << endl;
    cout << s.backspaceCompare("a##c", "#a#c") << endl;
    cout << s.backspaceCompare("a#c", "b") << endl;
    return 0;
}