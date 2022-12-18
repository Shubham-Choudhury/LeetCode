// Link: https://leetcode.com/problems/reconstruct-original-digits-from-english/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        vector<int> count(10, 0);
        for (char c : s) {
            if (c == 'z') count[0]++;
            if (c == 'w') count[2]++;
            if (c == 'u') count[4]++;
            if (c == 'x') count[6]++;
            if (c == 'g') count[8]++;
            if (c == 'o') count[1]++; // 1, 2, 4, 0
            if (c == 'h') count[3]++; // 3, 8
            if (c == 'f') count[5]++; // 5, 4
            if (c == 's') count[7]++; // 7, 6
            if (c == 'i') count[9]++; // 9, 5, 6, 8
        }
        count[1] -= count[0] + count[2] + count[4];
        count[3] -= count[8];
        count[5] -= count[4];
        count[7] -= count[6];
        count[9] -= count[5] + count[6] + count[8];
        string result;
        for (int i = 0; i < 10; i++) {
            result += string(count[i], '0' + i);
        }
        return result;
    }
};

int main()
{
    Solution s;
    cout << s.originalDigits("owoztneoe") << endl;
    cout << s.originalDigits("fviefuro") << endl;
    return 0;
}