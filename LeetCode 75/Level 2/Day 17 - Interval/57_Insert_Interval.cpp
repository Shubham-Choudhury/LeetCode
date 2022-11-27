// Link: https://leetcode.com/problems/insert-interval/?envType=study-plan&id=level-2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0;
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);
        while (i < intervals.size()) {
            result.push_back(intervals[i]);
            i++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = solution.insert(intervals, newInterval);
    for (auto &interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    return 0;
}