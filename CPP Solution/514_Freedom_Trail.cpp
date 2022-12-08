// Link: https://leetcode.com/problems/freedom-trail/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
    int dfs(int r, int k, vector<vector<int>> &dp, string &key, string &ring)
    {
        if(k == key.size())
            return 0;
        if(dp[r][k] != -1)
            return dp[r][k];
        int count = 0, clk = r, anticlk = r;
        //Clockwise Rotation
        while(key[k] != ring[clk])
        {
            clk++;
            count++;
            if(clk == ring.size())
                clk = 0;
        }
        dp[r][k] = count+1+dfs(clk, k+1, dp, key, ring);
        count = 0;
        while(key[k] != ring[anticlk])
        {
            anticlk--;
            count++;
            if(anticlk == -1)
                anticlk = ring.size()-1;
        }
        return dp[r][k] = min(dp[r][k], count+1+dfs(anticlk, k+1, dp, key, ring));
    }
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size(), m = key.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return dfs(0, 0, dp, key, ring);
    }
};

int main() {
    string ring = "godding";
    string key = "gd";
    Solution sol;
    cout << sol.findRotateSteps(ring, key) << endl;

    return 0;
}
