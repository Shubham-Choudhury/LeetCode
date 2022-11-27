// Link: https://leetcode.com/problems/maximum-profit-in-job-scheduling/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        sort(jobs.begin(), jobs.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> dp(n);
        dp[0] = jobs[0][2];
        for (int i = 1; i < n; i++) {
            int left = 0, right = i - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (jobs[mid][1] <= jobs[i][0]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            dp[i] = max(dp[i - 1], jobs[i][2] + (left > 0 ? dp[left - 1] : 0));
        }
        return dp[n - 1];
    }
};

int main() {
    Solution solution;
    vector<int> startTime = {1, 2, 3, 3};
    vector<int> endTime = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    cout << solution.jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}