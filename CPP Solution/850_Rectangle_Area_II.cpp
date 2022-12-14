// Link: https://leetcode.com/problems/rectangle-area-ii/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
#define ll long long
    ll MOD = 1e9 + 7;

    static bool cmp(vector<int> &v1, vector<int> &v2)
    {
        if (v1[0] == v2[0])
        {
            return v1[2] < v2[2];
        }
        return v1[0] < v2[0];
    }

    int rectangleArea(vector<vector<int>> &rectangles)
    {
        ll n = rectangles.size(), answer = 0;
        set<ll> ss;
        for (auto &x : rectangles)
        {
            ss.insert(x[1]);
            ss.insert(x[3]);
        }
        sort(rectangles.begin(), rectangles.end(), cmp);
        ll lower = *ss.begin();
        for (auto &x : ss)
        {
            ll upper = x;
            ll height = upper - lower;
            ll left = rectangles[0][0], right = left;
            for (auto &y : rectangles)
            {
                if (y[1] <= lower && y[3] >= upper)
                {
                    if (y[0] > right)
                    {
                        answer = (answer + height * (right - left)) % MOD;
                        left = y[0];
                    }
                    if (y[2] > right)
                    {
                        right = y[2];
                    }
                }
            }
            answer = (answer + height * (right - left)) % MOD;
            lower = upper;
        }
        return answer % MOD;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> rectangles = {{0, 0, 2, 2}, {1, 0, 2, 3}, {1, 0, 3, 1}};
    cout << solution.rectangleArea(rectangles) << endl;
    return 0;
}
