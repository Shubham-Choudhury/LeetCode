// Link: https://leetcode.com/problems/valid-square/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end());
        do {
            int d1 = dist(points[0], points[1]);
            int d2 = dist(points[1], points[2]);
            int d3 = dist(points[2], points[3]);
            int d4 = dist(points[3], points[0]);
            int d5 = dist(points[0], points[2]);
            int d6 = dist(points[1], points[3]);
            if (d1 == d2 && d2 == d3 && d3 == d4 && d5 == d6 && d1 != 0 && d5 != 0) {
                return true;
            }
        } while (next_permutation(points.begin(), points.end()));
        return false;
    }

private:
    int dist(vector<int>& p1, vector<int>& p2) {
        return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
    }
};

int main(void) {
    Solution sol;
    vector<int> p1 = {0, 0};
    vector<int> p2 = {1, 1};
    vector<int> p3 = {1, 0};
    vector<int> p4 = {0, 1};
    cout << sol.validSquare(p1, p2, p3, p4) << endl;
    return 0;
}
