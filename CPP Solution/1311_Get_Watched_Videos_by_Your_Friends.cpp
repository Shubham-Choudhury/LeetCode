// Link: https://leetcode.com/problems/get-watched-videos-by-your-friends/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(id);
        visited[id] = 1;
        while (!q.empty() && level > 0) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                int u = q.front();
                q.pop();
                for (int v : friends[u]) {
                    if (visited[v] == 0) {
                        q.push(v);
                        visited[v] = 1;
                    }
                }
            }
            level--;
        }
        map<string, int> mp;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (string video : watchedVideos[u]) {
                mp[video]++;
            }
        }
        vector<pair<int, string>> v;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            v.push_back({it->second, it->first});
        }
        sort(v.begin(), v.end());
        vector<string> ans;
        for (int i = 0; i < v.size(); i++) {
            ans.push_back(v[i].second);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> watchedVideos = {{"A","B"},{"C"},{"B","C"},{"D"}};
    vector<vector<int>> friends = {{1,2},{0,3},{0,3},{1,2}};
    int id = 0, level = 1;
    vector<string> ans = sol.watchedVideosByFriends(watchedVideos, friends, id, level);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
