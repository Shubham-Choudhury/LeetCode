// Link: https://leetcode.com/problems/minimum-area-rectangle-ii/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double minAreaFreeRect(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<string, vector<vector<int>>> m;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int x1 = points[i][0], y1 = points[i][1], x2 = points[j][0], y2 = points[j][1];
                int x = x1 + x2, y = y1 + y2;
                double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
                string key = to_string(x) + "," + to_string(y) + "," + to_string(d);
                m[key].push_back({x1, y1, x2, y2});
            }
        double res = INT_MAX;
        for (auto &p : m)
        {
            auto &v = p.second;
            for (int i = 0; i < v.size(); ++i)
                for (int j = i + 1; j < v.size(); ++j)
                {
                    int x1 = v[i][0], y1 = v[i][1], x2 = v[i][2], y2 = v[i][3];
                    int x3 = v[j][0], y3 = v[j][1], x4 = v[j][2], y4 = v[j][3];
                    double area = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)) * sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
                    res = min(res, area);
                }
        }
        return res == INT_MAX ? 0 : res;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points = {{1, 2}, {2, 1}, {1, 0}, {0, 1}};
    cout << sol.minAreaFreeRect(points) << endl;
    return 0;
}
