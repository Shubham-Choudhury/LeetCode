// Link: https://leetcode.com/problems/loud-and-rich/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>> adj(n);
        for(auto &v: richer){
            adj[v[1]].push_back(v[0]);
        }
        vector<int> ans(n, -1);
        for(int i = 0; i < n; ++i){
            dfs(i, adj, quiet, ans);
        }
        return ans;
    }
    
    int dfs(int u, vector<vector<int>> &adj, vector<int> &quiet, vector<int> &ans){
        if(ans[u] != -1) return ans[u];
        ans[u] = u;
        for(auto &v: adj[u]){
            int x = dfs(v, adj, quiet, ans);
            if(quiet[x] < quiet[ans[u]]) ans[u] = x;
        }
        return ans[u];
    }
};

int main(){
    Solution s;
    vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
    vector<int> quiet = {3,2,5,4,6,1,7,0};
    vector<int> ans = s.loudAndRich(richer, quiet);
    for(auto &x: ans) cout << x << " ";
    cout << endl;
    return 0;
}