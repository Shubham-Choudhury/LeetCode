// Link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                res += (char)('a' + (s[i] - '0') * 10 + (s[i + 1] - '0') - 1);
                i += 2;
            } else {
                res += (char)('a' + s[i] - '1');
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "10#11#12";
    cout << s.freqAlphabets(str) << endl;
    return 0;
}