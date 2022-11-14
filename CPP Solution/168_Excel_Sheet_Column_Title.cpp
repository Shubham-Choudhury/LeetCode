// Link: https://leetcode.com/problems/excel-sheet-column-title/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string result = "";
        while (n > 0) {
            n--;
            result = (char)('A' + n % 26) + result;
            n /= 26;
        }
        return result;
    }
};

int main() {
    Solution s;
    int n = 701;
    string result = s.convertToTitle(n);
    cout << result << endl;
    return 0;
}