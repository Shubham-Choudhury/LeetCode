// Link: https://leetcode.com/problems/max-points-on-a-line/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for (int i = 0; i < points.size(); i++) {
            int same = 1, vertical = 0, maxPoints = 0;
            unordered_map<double, int> m;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
                    same++;
                else if (points[i][0] == points[j][0])
                    vertical++;
                else {
                    double slope = (double)(points[i][1] - points[j][1]) / (points[i][0] - points[j][0]);
                    m[slope]++;
                    maxPoints = max(maxPoints, m[slope]);
                }
            }
            maxPoints = max(maxPoints, vertical);
            res = max(res, maxPoints + same);
        }
        return res;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << obj.maxPoints(points);
    return 0;
}