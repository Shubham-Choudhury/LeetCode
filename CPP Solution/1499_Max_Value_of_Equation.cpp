// Link: https://leetcode.com/problems/max-value-of-equation/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        int ans = INT_MIN;
        deque<pair<int, int>> dq;
        for (int i = 0; i < n; i++)
        {
            while (!dq.empty() && points[i][0] - dq.front().first > k)
            {
                dq.pop_front();
            }
            if (!dq.empty())
            {
                ans = max(ans, points[i][0] + points[i][1] + dq.front().second);
            }
            while (!dq.empty() && points[i][1] - points[i][0] > dq.back().second)
            {
                dq.pop_back();
            }
            dq.push_back({points[i][0], points[i][1] - points[i][0]});
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> points;
    int k, ans;

    // Output: 4
    points = {{1, 3}, {2, 0}, {5, 10}, {6, -10}};
    k = 1;
    ans = sol.findMaxValueOfEquation(points, k);
    cout << ans << endl;

    // Output: 6
    points = {{0, 0}, {3, 0}, {9, 2}};
    k = 3;
    ans = sol.findMaxValueOfEquation(points, k);
    cout << ans << endl;

    return 0;
}
