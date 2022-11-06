// Link: https://leetcode.com/problems/to-lower-case/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] += 32;
            }
        }
        return str;
    }
};

int main() {
    Solution s;
    string str = "Hello";
    cout << s.toLowerCase(str) << endl;
    return 0;
}