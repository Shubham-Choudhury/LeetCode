// Link: https://leetcode.com/problems/longest-well-performing-interval/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> prefix(n + 1);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (hours[i] > 8 ? 1 : -1);
        }
        int ans = 0;
        stack<int> s;
        for (int i = 0; i <= n; i++) {
            if (s.empty() || prefix[i] < prefix[s.top()]) {
                s.push(i);
            }
        }
        for (int i = n; i >= 0; i--) {
            while (!s.empty() && prefix[i] > prefix[s.top()]) {
                ans = max(ans, i - s.top());
                s.pop();
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> hours = {9,9,6,0,6,6,9};
    cout << s.longestWPI(hours) << endl;
    return 0;
}
