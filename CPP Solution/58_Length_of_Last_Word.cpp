// Link: https://leetcode.com/problems/length-of-last-word/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == ' ') {
                if(ans == 0) continue;
                else break;
            }
            ans++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    string s1 = "Hello World";
    string s2 = " ";
    cout << s.lengthOfLastWord(s1) << endl;
    cout << s.lengthOfLastWord(s2) << endl;
    return 0;
}