// Link: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/?envType=study-plan&id=programming-skills-i

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INT_MAX 2147483647

class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
        int n = points.size();
        int ans = -1;
        int min_dist = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(points[i][0]==x || points[i][1]==y)
            {
                int dist = abs(points[i][0]-x)+abs(points[i][1]-y);
                if(dist<min_dist)
                {
                    min_dist = dist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};

int main() {
    int x, y;
    cin >> x >> y;
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    Solution s;
    cout << s.nearestValidPoint(x, y, points) << endl;
    return 0;
}