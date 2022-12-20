// Link: https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector <vector<int>> intervals;
        for (int i = 0; i < ranges.size(); i++) {
            vector<int> inter{i - ranges[i], i + ranges[i]};
            intervals.push_back(inter);
        }
        sort(intervals.begin(), intervals.end(), [](auto &p, auto &q){
            return (p[0] < q[0]);
        });
        int count = 0, start_time = 0, end_time = 0, i = 0;
        
        while (end_time < n) {
            for (; i < intervals.size() && intervals[i][0] <= start_time; i++) {
                end_time = max(end_time, intervals[i][1]);
            }
            if (start_time == end_time) return -1;
            start_time = end_time;
            count++;
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> ranges;
    int n;
    
    n = 5;
    ranges = {3,4,1,1,0,0};
    cout << sol.minTaps(n, ranges) << endl;
    
    n = 3;
    ranges = {0,0,0,0};
    cout << sol.minTaps(n, ranges) << endl;
    
    n = 7;
    ranges = {1,2,1,0,2,1,0,1};
    cout << sol.minTaps(n, ranges) << endl;
    
    n = 8;
    ranges = {4,0,0,0,0,0,0,0,4};
    cout << sol.minTaps(n, ranges) << endl;
    
    n = 8;
    ranges = {4,0,0,0,4,0,0,0,4};
    cout << sol.minTaps(n, ranges) << endl;
    
    return 0;
}
