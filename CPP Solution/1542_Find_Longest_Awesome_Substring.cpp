// Link: https://leetcode.com/problems/find-longest-awesome-substring/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestAwesome(string s) {
        int n = s.size();
        int ans = 0;
        vector<int>dp(1024,-1);
        dp[0] = 0;
        int mask = 0;
        for(int i = 0 ; i < n ; i ++){
            mask ^= (1<<(s[i]-'0'));
            if(dp[mask] != -1){
                ans = max(ans,i+1-dp[mask]);
            }
            for(int j = 0 ; j < 10 ; j ++){
                int new_mask = mask ^ (1<<j);
                if(dp[new_mask] != -1){
                    ans = max(ans,i+1-dp[new_mask]);
                }
            }
            if(dp[mask] == -1){
                dp[mask] = i+1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string s;
    int ans;

    // Output: 5
    s = "3242415";
    ans = sol.longestAwesome(s);
    cout << ans << endl;

    // Output: 1
    s = "12345678";
    ans = sol.longestAwesome(s);
    cout << ans << endl;

    // Output: 0
    s = "213123";
    ans = sol.longestAwesome(s);
    cout << ans << endl;

    // Output: 2
    s = "00";
    ans = sol.longestAwesome(s);
    cout << ans << endl;

    return 0;
}
