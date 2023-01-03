// Link: https://leetcode.com/problems/minimum-area-rectangle/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int ans = INT_MAX;
        unordered_map<int, set<int>> m;
        for (vector<int> point : points)
        {
            m[point[0]].insert(point[1]);
        }
        for (int i = 0; i < points.size(); i++)
        {
            for (int j = i + 1; j < points.size(); j++)
            {
                if (points[i][0] != points[j][0] && points[i][1] != points[j][1])
                {
                    if (m[points[i][0]].count(points[j][1]) && m[points[j][0]].count(points[i][1]))
                    {
                        ans = min(ans, abs(points[i][0] - points[j][0]) * abs(points[i][1] - points[j][1]));
                    }
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> points = {{1,1},{1,3},{3,1},{3,3},{2,2}};
    cout << sol.minAreaRect(points) << endl;
    return 0;
    
}