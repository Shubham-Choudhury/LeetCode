// Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string text) {
        int n = text.size();
        vector<int> cnt(26, 0);
        vector<bool> visited(26, false);
        for (int i = 0; i < n; i++) {
            cnt[text[i] - 'a']++;
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            cnt[text[i] - 'a']--;
            if (visited[text[i] - 'a']) {
                continue;
            }
            while (ans.size() > 0 && ans.back() > text[i] && cnt[ans.back() - 'a'] > 0) {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans.push_back(text[i]);
            visited[text[i] - 'a'] = true;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string text;
    cin >> text;
    cout << sol.smallestSubsequence(text) << endl;
    return 0;
}
