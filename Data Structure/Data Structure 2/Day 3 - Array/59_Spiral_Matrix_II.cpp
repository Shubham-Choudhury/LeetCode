// Link: https://leetcode.com/problems/spiral-matrix-ii/?envType=study-plan&id=data-structure-ii

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int l = 0;
        int r = n - 1;
        int t = 0;
        int b = n - 1;
        int num = 1;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) {
                result[t][i] = num++;
            }
            t++;
            for (int i = t; i <= b; i++) {
                result[i][r] = num++;
            }
            r--;
            for (int i = r; i >= l; i--) {
                result[b][i] = num++;
            }
            b--;
            for (int i = b; i >= t; i--) {
                result[i][l] = num++;
            }
            l++;
        }
        return result;
    }
};

int main() {
    Solution sol;
    int n;
    vector<vector<int>> result;
    
    n = 3;
    result = sol.generateMatrix(n);
    for (auto& i : result) {
        for (auto& j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}