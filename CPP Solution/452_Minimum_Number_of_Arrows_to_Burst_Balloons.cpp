// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if (n == 0) {
            return 0;
        }
        vector<pair<int, int> >a;
        for (int i = 0; i<n; i++) {
            a.push_back({points[i][0], points[i][1]});
        }
        sort(a.begin(), a.end(), comp);
        int arrows = 1;
        int fin = a[0].second;
        if (n == 1) {
            return 1;
        }
        for (int i = 1; i<n; i++) {
            if (a[i].first <= fin) {
                continue;
            }
            else {
                arrows++;
                fin = a[i].second;
            }
        }
        return arrows;
    }
};

int main() {
    Solution s;
    vector<vector<int> > points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    cout << s.findMinArrowShots(points) << endl;
    return 0;
}
