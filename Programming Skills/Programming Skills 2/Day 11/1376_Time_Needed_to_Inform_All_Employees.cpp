// Link: https://leetcode.com/problems/time-needed-to-inform-all-employees/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (manager[i] != -1) {
                adj[manager[i]].push_back(i);
            }
        }
        int ans = 0;
        queue<pair<int, int>> q;
        q.push({headID, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            ans = max(ans, p.second);
            for (int i = 0; i < adj[p.first].size(); i++) {
                q.push({adj[p.first][i], p.second + informTime[p.first]});
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> manager = {2, 2, -1, 2, 2, 2};
    vector<int> informTime = {0, 0, 1, 0, 0, 0};
    cout << sol.numOfMinutes(6, 2, manager, informTime) << endl;
    return 0;
}