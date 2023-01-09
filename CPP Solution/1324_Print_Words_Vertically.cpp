// Link: https://leetcode.com/problems/print-words-vertically/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        vector<string> ans;
        int n = s.size();
        int max_len = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] != ' ') {
                j++;
            }
            max_len = max(max_len, j - i);
            i = j + 1;
        }
        for (int i = 0; i < max_len; i++) {
            string str = "";
            int j = 0;
            while (j < n) {
                if (s[j] == ' ') {
                    str += ' ';
                    j++;
                } else {
                    int k = j;
                    while (k < n && s[k] != ' ') {
                        k++;
                    }
                    if (k - j > i) {
                        str += s[j + i];
                    } else {
                        str += ' ';
                    }
                    j = k + 1;
                }
            }
            while (str.size() > 0 && str.back() == ' ') {
                str.pop_back();
            }
            ans.push_back(str);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "HOW ARE YOU";
    vector<string> ans = sol.printVertically(s);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
