// Link: https://leetcode.com/problems/triangle/?envType=study-plan&id=algorithm-i

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        triangle[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> triangle[i][j];
        }
    }
    Solution obj;
    cout << obj.minimumTotal(triangle) << endl;
    return 0;
}