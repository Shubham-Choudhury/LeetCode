// Link: https://leetcode.com/problems/maximum-number-of-visible-points/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int extra = 0;
        for (auto& p : points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                ++extra;
                continue;
            }
            angles.push_back(atan2(p[1] - location[1], p[0] - location[0]) * 180 / M_PI);
        }
        sort(angles.begin(), angles.end());
        int n = angles.size();
        for (int i = 0; i < n; ++i)
            angles.push_back(angles[i] + 360);
        int res = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            while (j < angles.size() && angles[j] - angles[i] <= angle)
                ++j;
            res = max(res, j - i);
        }
        return res + extra;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{2,1},{2,2},{3,3}};
    vector<int> c = {1,1};
    cout << a.visiblePoints(b, 90, c) << endl;
    return 0;
}
