// Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(), events.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        int i = 0;
        for (int d = 1; d <= 100000; d++) {
            while (!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            while (i < n && events[i][0] == d) {
                pq.push(events[i][1]);
                i++;
            }
            if (!pq.empty()) {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    cout << sol.maxEvents(events) << endl;
    return 0;
}
