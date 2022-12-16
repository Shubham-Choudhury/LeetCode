// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] >= stations[i][0]) {
                    dp[j + 1] = max(dp[j + 1], dp[j] + stations[i][1]);
                }
            }
        }
        for (int i = 0; i <= n; i++) {
            if (dp[i] >= target) {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> stations;
    int target;
    int startFuel;

    // Output: 2
    target = 1, startFuel = 1, stations = {};
    cout << sol.minRefuelStops(target, startFuel, stations) << endl;

    // Output: -1
    target = 100, startFuel = 1, stations = {{10, 100}};
    cout << sol.minRefuelStops(target, startFuel, stations) << endl;

    return 0;
}