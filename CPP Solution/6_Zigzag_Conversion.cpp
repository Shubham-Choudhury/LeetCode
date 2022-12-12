// Link: https://leetcode.com/problems/zigzag-conversion/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string result = "";
        int n = s.length();
        int cycleLen = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n)
                    result += s[j + cycleLen - i];
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    cout << sol.convert(s, numRows) << endl;
    return 0;
}
