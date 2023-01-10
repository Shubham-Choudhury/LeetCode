// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
    {
        int x = max(x1, min(x_center, x2));
        int y = max(y1, min(y_center, y2));
        int distance = pow(x - x_center, 2) + pow(y - y_center, 2);
        return distance <= pow(radius, 2);
    }
};

int main()
{
    Solution s;
    int radius = 1, x_center = 0, y_center = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1;
    cout << s.checkOverlap(radius, x_center, y_center, x1, y1, x2, y2) << endl;
    return 0;
}
