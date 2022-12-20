// Link: https://leetcode.com/problems/jump-game-iv/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> idx;
        for (int i = 0; i < n; i++) {
            idx[arr[i]].push_back(i);
        }
        vector<int> dp(n, n);
        dp[0] = 0;
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i - 1 >= 0 && dp[i - 1] > dp[i] + 1) {
                dp[i - 1] = dp[i] + 1;
                q.push(i - 1);
            }
            if (i + 1 < n && dp[i + 1] > dp[i] + 1) {
                dp[i + 1] = dp[i] + 1;
                q.push(i + 1);
            }
            for (int j : idx[arr[i]]) {
                if (dp[j] > dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    q.push(j);
                }
            }
            idx[arr[i]].clear();
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    
    arr = {100,-23,-23,404,100,23,23,23,3,404};
    cout << sol.minJumps(arr) << endl;
    
    arr = {7};
    cout << sol.minJumps(arr) << endl;
    
    arr = {7,6,9,6,9,6,9,7};
    cout << sol.minJumps(arr) << endl;
    
    arr = {6,1,9};
    cout << sol.minJumps(arr) << endl;
    
    arr = {11,22,7,7,7,7,7,7,7,22,13};
    cout << sol.minJumps(arr) << endl;
    
    return 0;
}
