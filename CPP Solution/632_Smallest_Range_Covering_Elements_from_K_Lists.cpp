// Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> idx(k, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int minVal = INT_MAX, maxVal = INT_MIN;
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i});
            maxVal = max(maxVal, nums[i][0]);
        }
        int range = INT_MAX;
        vector<int> res;
        while (true) {
            auto p = pq.top();
            pq.pop();
            minVal = p.first;
            if (maxVal - minVal < range) {
                range = maxVal - minVal;
                res = {minVal, maxVal};
            }
            if (idx[p.second] + 1 == nums[p.second].size())
                break;
            idx[p.second]++;
            pq.push({nums[p.second][idx[p.second]], p.second});
            maxVal = max(maxVal, nums[p.second][idx[p.second]]);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> res = s.smallestRange(nums);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}