// Link: https://leetcode.com/problems/ipo/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = (int) Profits.size();
        vector<pair<int, int>> projects;
        for (int i = 0; i < n; ++ i)
            projects.push_back({Capital[i], Profits[i]});
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int i = 0;
        while (k --) {
            while (i < n && projects[i].first <= W)
                pq.push(projects[i ++].second);
            if (pq.empty())
                break;
            W += pq.top();
            pq.pop();
        }
        return W;
    }
};

int main() {
    vector<int> Profits = {1, 2, 3};
    vector<int> Capital = {0, 1, 1};
    Solution sol;
    cout << sol.findMaximizedCapital(2, 0, Profits, Capital) << endl;

    return 0;
}
