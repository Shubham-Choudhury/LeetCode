// Link: https://leetcode.com/problems/maximum-69-number/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '6'){
                s[i] = '9';
                break;
            }
        }
        return stoi(s);
    }
};

int main() {
    int num;
    cin >> num;
    Solution obj;
    cout << obj.maximum69Number(num) << endl;
    return 0;
}