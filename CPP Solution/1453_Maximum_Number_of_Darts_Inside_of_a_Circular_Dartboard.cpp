// Link: https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    const double tol = 1e-6;
    double R;

    struct Point
    {
        double x, y;
    };

    vector<Point> point;

    double dis(const Point &a, const Point &b)
    {
        return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    pair<Point, Point> getCenter(const Point &a, const Point &b)
    {
        Point mid;
        pair<Point, Point> res;
        mid.x = (a.x + b.x) / 2, mid.y = (a.y + b.y) / 2;
        double theta = atan2(a.y - b.y, b.x - a.x);
        double tmp = dis(a, b) / 2;
        double d = sqrt(R * R - tmp * tmp);
        res.first.x = mid.x - d * sin(theta);
        res.first.y = mid.y - d * cos(theta);
        res.second.x = mid.x + d * sin(theta);
        res.second.y = mid.y + d * cos(theta);
        return res;
    }

    int numPoints(vector<vector<int>> &points, int r)
    {
        int n = points.size();
        R = (double)r;
        point.resize(n);
        for (int i = 0; i < n; ++i)
        {
            point[i].x = points[i][0];
            point[i].y = points[i][1];
        }
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j || dis(point[i], point[j]) - 2 * R > tol)
                    continue;
                int cnt = 0;
                auto p = getCenter(point[i], point[j]);
                for (int k = 0; k < n; k++)
                {
                    if (dis(point[k], p.first) - R <= tol)
                        cnt++;
                }
                ans = max(ans, cnt);
                cnt = 0;
                for (int k = 0; k < n; k++)
                {
                    if (dis(point[k], p.second) - R <= tol)
                        cnt++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};

int main(void)
{
    Solution sol;
    vector<vector<int>> points = {{1, 2}, {3, 5}, {1, -1}, {2, 3}, {4, 1}, {1, 3}};
    int r = 2;
    int res = sol.numPoints(points, r);
    cout << res << endl;
    return 0;
}
