// Link: https://leetcode.com/problems/score-after-flipping-matrix/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            if (A[i][0] == 0) {
                for (int j = 0; j < n; j++) {
                    A[i][j] = 1 - A[i][j];
                }
            }
        }
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int i = 0; i < m; i++) {
                if (A[i][j] == 1) {
                    cnt++;
                }
            }
            ans += max(cnt, m - cnt) * (1 << (n - j - 1));
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<vector<int>> A = {{0,0,1,1},{1,0,1,0},{1,1,0,0}};
    cout << s.matrixScore(A) << endl;
    return 0;
}