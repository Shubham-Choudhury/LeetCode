// Link: https://leetcode.com/problems/reorganize-string/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string S) {
        int n = S.size();
        vector<int> count(26);
        for (char c : S) {
            count[c - 'a'] += 100;
        }
        for (int i = 0; i < 26; i++) {
            count[i] += i;
        }
        sort(count.begin(), count.end());
        string ans(n, ' ');
        int t = 1;
        for (int code : count) {
            int ct = code / 100;
            char ch = 'a' + (code % 100);
            if (ct > (n + 1) / 2) {
                return "";
            }
            for (int i = 0; i < ct; i++) {
                if (t >= n) {
                    t = 0;
                }
                ans[t] = ch;
                t += 2;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string S;
    string ans;

    // Output: "aba"
    S = "aab";
    ans = sol.reorganizeString(S);
    cout << ans << endl;

    // Output: ""
    S = "aaab";
    ans = sol.reorganizeString(S);
    cout << ans << endl;

    return 0;
}