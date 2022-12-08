// Link: https://leetcode.com/problems/the-skyline-problem/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> heights;
        for (auto& b : buildings) {
            heights.push_back({b[0], -b[2]});
            heights.push_back({b[1], b[2]});
        }
        sort(heights.begin(), heights.end());
        multiset<int> m;
        m.insert(0);
        int prev = 0;
        for (auto& h : heights) {
            if (h.second < 0) m.insert(-h.second);
            else m.erase(m.find(h.second));
            int cur = *m.rbegin();
            if (cur != prev) {
                res.push_back({h.first, cur});
                prev = cur;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    Solution sol;
    vector<vector<int>> res = sol.getSkyline(buildings);
    for (auto& r : res) {
        cout << r[0] << " " << r[1] << endl;
    }
    
    return 0;
}
