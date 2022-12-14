// Link: https://leetcode.com/problems/stickers-to-spell-word/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;

class Solution {
private:
    const int INF = 1061109567;
public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> cnt(n, vector<int>(26, 0));
        for (int i = 0; i < n; i++) {
            for (char c : stickers[i]) {
                cnt[i][c - 'a']++;
            }
        }
        vector<int> dp(1 << target.size(), INF);
        dp[0] = 0;
        for (int state = 0; state < (1 << target.size()); state++) {
            if (dp[state] == INF) {
                continue;
            }
            for (int i = 0; i < n; i++) {
                int now = state;
                for (char c : stickers[i]) {
                    for (int j = 0; j < target.size(); j++) {
                        if (((now >> j) & 1) == 0 && c == target[j]) {
                            now |= (1 << j);
                            break;
                        }
                    }
                }
                dp[now] = min(dp[now], dp[state] + 1);
            }
        }
        return dp[(1 << target.size()) - 1] == INF ? -1 : dp[(1 << target.size()) - 1];
    }
};

int main(){
    Solution s;
    vector<string> stickers = {"with", "example", "science"} ;
    string target = "thehat" ;
    cout << s.minStickers(stickers, target) << endl;
    return 0;
}
