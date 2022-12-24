// Link: https://leetcode.com/problems/best-position-for-a-service-centre/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
   double getMinDistSum(vector<vector<int>>& pos) {
    double left = 100, bottom = 100, right = 0, top = 0;
    for (auto &p : pos) {
        left = min(left, (double)p[0]);
        bottom = min(bottom, (double)p[1]);
        right = max(right, (double)p[0]);
        top = max(top, (double)p[1]);
    }
    double res = DBL_MAX, res_x = 0, res_y = 0;
    for (double delta = 10; delta >= 0.00001; delta /= 10) {
        for (double x = left; x <= right; x += delta)
            for (double y = bottom; y <= top; y += delta) {
                double d = 0;
                for (auto &p : pos)
                    d += sqrt((p[0] - x) * (p[0] - x) + (p[1] - y) * (p[1] - y));
                if (res > d) {
                    res = d;
                    res_x = x;
                    res_y = y;
                }
            }
        left = res_x - delta;
        bottom = res_y - delta;
        right = res_x + delta * 2;
        top = res_y + delta * 2;
    }
    return res == DBL_MAX ? 0 : res;
}
};

int main()
{
    Solution sol;
    vector<vector<int>> positions;
    double ans;

    // Output: 2.00000
    positions = {{0, 1}, {1, 0}, {1, 2}, {2, 1}};
    ans = sol.getMinDistSum(positions);
    cout << ans << endl;

    // Output: 4.00000
    positions = {{1, 1}, {3, 3}};
    ans = sol.getMinDistSum(positions);
    cout << ans << endl;

    // Output: 32.94036
    positions = {{1, 1}};
    ans = sol.getMinDistSum(positions);
    cout << ans << endl;

    // Output: 4.74342
    positions = {{1, 1}, {0, 0}, {2, 0}};
    ans = sol.getMinDistSum(positions);
    cout << ans << endl;

    // Output: 4.49999
    positions = {{0, 1}, {3, 2}, {4, 5}, {7, 6}, {8, 9}, {11, 1}, {2, 12}};
    ans = sol.getMinDistSum(positions);
    cout << ans << endl;

    return 0;
}
