// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> cnt(3, 0);
        int ans = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            cnt[s[j] - 'a']++;
            while (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                cnt[s[i] - 'a']--;
                i++;
            }
            ans += i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl;
    return 0;
}
