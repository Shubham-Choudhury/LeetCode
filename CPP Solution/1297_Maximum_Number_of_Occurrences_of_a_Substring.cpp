// Link: https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            set<char> st;
            string str = "";
            for (int j = i; j < n; j++) {
                st.insert(s[j]);
                str += s[j];
                if (st.size() > maxLetters) break;
                if (str.size() >= minSize && str.size() <= maxSize) {
                    mp[str]++;
                }
            }
        }
        int ans = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            ans = max(ans, it->second);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "aababcaab";
    int maxLetters = 2, minSize = 3, maxSize = 4;
    cout << sol.maxFreq(s, maxLetters, minSize, maxSize) << endl;
    return 0;
}
