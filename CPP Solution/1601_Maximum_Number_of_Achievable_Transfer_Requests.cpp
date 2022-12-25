// Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        int res = 0;
        for (int i = 0; i < (1 << requests.size()); ++i) {
            vector<int> cnt(n);
            int cnt_req = 0;
            for (int j = 0; j < requests.size(); ++j)
                if (i & (1 << j)) {
                    ++cnt[requests[j][0]];
                    --cnt[requests[j][1]];
                    ++cnt_req;
                }
            if (all_of(cnt.begin(), cnt.end(), [](int x) { return x == 0; }))
                res = max(res, cnt_req);
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{0,1},{1,0},{1,2},{2,0},{3,4},{5,6},{5,7},{7,5}};
    cout << a.maximumRequests(8, b) << endl;
    return 0;
}
