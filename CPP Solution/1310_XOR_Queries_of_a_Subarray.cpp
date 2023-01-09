// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        vector<int> ans;
        for (auto query : queries) {
            int l = query[0], r = query[1];
            ans.push_back(prefix[r + 1] ^ prefix[l]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {0, 3}, {3, 3}};
    vector<int> ans = sol.xorQueries(arr, queries);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
