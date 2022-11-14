// Link: https://leetcode.com/problems/k-closest-points-to-origin/?envType=study-plan&id=programming-skills-ii

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < points.size(); i++) {
            int dist = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dist, i});
            if (pq.size() > K) {
                pq.pop();
            }
        }
        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<int>> points = {{1, 3}, {-2, 2}};
    vector<vector<int>> result = s.kClosest(points, 1);
    for (vector<int> v : result) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}