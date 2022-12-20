// Link: https://leetcode.com/problems/longest-happy-prefix/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;
        while (i < n) {
            if (s[i] == s[j]) {
                lps[i] = j + 1;
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return s.substr(0, lps[n - 1]);
    }
};

int main()
{
    Solution s;
    string s1 = "level";
    cout << s.longestPrefix(s1) << endl;
    string s2 = "ababab";
    cout << s.longestPrefix(s2) << endl;
    string s3 = "leetcode";
    cout << s.longestPrefix(s3) << endl;

    return 0;

}