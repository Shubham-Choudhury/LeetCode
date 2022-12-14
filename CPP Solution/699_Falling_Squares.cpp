// Link: https://leetcode.com/problems/falling-squares/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> tree;

    int queryRange(int node, int start, int end, int l, int r) {
        if (l > r)
            return 0;
        if (l == start && r == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        return max(queryRange(2 * node, start, mid, l, min(r, mid)), queryRange(2 * node + 1, mid + 1, end, max(l, mid + 1), r));
    }

    void assignRange(int node, int start, int end, int l, int r, int val)
    {

        if (start > end or start > r or end < l)
            return;


        if (start == end)
        {

            tree[node] = val;
            return;
        }


        int mid = (start + end) / 2;
        assignRange(node * 2, start, mid, l, r, val);
        assignRange(node * 2 + 1, mid + 1, end, l, r, val);


        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }


    vector<vector<int>> compressedArrayRange(vector<vector<int>> a) {
        int n = a.size();
        vector<int> b(2 * n);
        vector<pair<int, int>> pairs(2 * n);
        for (int i = 0; i < n; ++i) {
            pairs[2 * i] = {a[i][0], 2 * i};
            pairs[2 * i + 1] = {a[i][0] + a[i][1], 2 * i + 1};
        }
        sort(pairs.begin(), pairs.end());
        int nxt = 0;
        for (int i = 0; i < 2 * n; ++i) {
            if (i > 0 && pairs[i - 1].first != pairs[i].first) nxt++;
            b[pairs[i].second] = nxt;
        }

        vector<vector<int>> cp(n, vector<int>(2));

        for(int i=0; i<n; i++){
            cp[i][0] = b[2 * i];
            cp[i][1] = b[2 * i + 1];
        }

        return cp;
    }

    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();

        vector<vector<int>> cp = compressedArrayRange(positions);

        vector<int> ans;
        
        int N = INT_MIN;

        for(int i=0; i<n; i++){
            N = max(N, cp[i][1]);
        }
        
        tree.resize(4 * N, 0);

        int curMax = 0, globMax = 0;

        for(int i=0; i<n; i++){
            int l = cp[i][0], r = cp[i][1] - 1;

            curMax = queryRange(1, 0, N - 1, l, r);

            int newMax = curMax + positions[i][1];

            assignRange(1, 0, N-1, l, r, newMax);

            globMax = max(newMax, globMax);

            ans.push_back(globMax);
        }
        
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> positions = {{1, 2}, {2, 3}, {6, 1}} ;
    vector<int> res = s.fallingSquares(positions);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}
