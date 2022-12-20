// Link: https://leetcode.com/problems/jump-game-v/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, 1);
        vector<int> idx(n);
        for (int i = 0; i < n; i++) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return arr[a] < arr[b];
        });
        for (int i = 0; i < n; i++) {
            int j = idx[i];
            for (int k = j - 1; k >= max(0, j - d); k--) {
                if (arr[k] >= arr[j]) {
                    break;
                }
                dp[j] = max(dp[j], dp[k] + 1);
            }
            for (int k = j + 1; k <= min(n - 1, j + d); k++) {
                if (arr[k] >= arr[j]) {
                    break;
                }
                dp[j] = max(dp[j], dp[k] + 1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    vector<int> arr;
    int d;
    
    arr = {6,4,14,6,8,13,9,7,10,6,12}, d = 2;
    cout << sol.maxJumps(arr, d) << endl;
    
    arr = {3,3,3,3,3}, d = 3;
    cout << sol.maxJumps(arr, d) << endl;
    
    arr = {7,6,5,4,3,2,1}, d = 1;
    cout << sol.maxJumps(arr, d) << endl;
    
    arr = {7,1,7,1,7,1}, d = 2;
    cout << sol.maxJumps(arr, d) << endl;
    
    arr = {66}, d = 1;
    cout << sol.maxJumps(arr, d) << endl;
    
    return 0;
}
