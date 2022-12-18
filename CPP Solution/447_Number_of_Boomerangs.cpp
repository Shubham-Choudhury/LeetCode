// Link: https://leetcode.com/problems/number-of-boomerangs/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int result = 0;
        for (int i = 0; i < points.size(); i++)
        {
            unordered_map<int, int> map;
            for (int j = 0; j < points.size(); j++)
            {
                if (i == j)
                    continue;
                int distance = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                map[distance]++;
            }
            for (auto it = map.begin(); it != map.end(); it++)
                result += it->second * (it->second - 1);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    cout << s.numberOfBoomerangs(points) << endl;
    return 0;
}
