// Link: https://leetcode.com/problems/goal-parser-interpretation/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string ans = "";
        for(int i = 0; i < command.size(); i++) {
            if(command[i] == 'G') {
                ans += 'G';
            } else if(command[i] == '(' && command[i + 1] == ')') {
                ans += 'o';
                i++;
            } else {
                ans += "al";
                i += 3;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.interpret("G()(al)") << endl;
    cout << s.interpret("G()()()()(al)") << endl;
    cout << s.interpret("(al)G(al)()()G") << endl;
    return 0;
}