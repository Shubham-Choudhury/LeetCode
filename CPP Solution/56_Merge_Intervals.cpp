// Link: https://leetcode.com/problems/merge-intervals/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < n; i++) {
            int low = intervals[i][0];
            int high = intervals[i][1];
            while (i < n - 1 && high >= intervals[i + 1][0]) {
                high = max(high, intervals[i + 1][1]);
                i++;
            }
            res.push_back({low, high});
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = solution.merge(intervals);
    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;
}