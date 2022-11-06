// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/?envType=study-plan&id=binary-search-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        vector<pair<int, int>> v;
        for (int i = 0; i < mat.size(); i++) {
            int count = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) {
                    count++;
                }
            }
            v.push_back({count, i});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].second);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    int k = 3;
    vector<int> res = s.kWeakestRows(mat, k);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}