// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (int i = 0; i < n; i++) {
            cnt[s[i] - 'a']++;
            cnt[t[i] - 'a']--;
        }
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] > 0) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "bab";
    string t = "aba";
    cout << sol.minSteps(s, t) << endl;
    return 0;
}
