// Link: https://leetcode.com/problems/car-fleet/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        int n = position.size();
        vector<pair<int, int>> cars;
        for (int i = 0; i < n; ++i)
        {
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end());
        int ans = 0;
        double prev = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            double time = (double)(target - cars[i].first) / cars[i].second;
            if (time > prev)
            {
                ans++;
                prev = time;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed = {2, 4, 1, 1, 3};
    cout << s.carFleet(12, position, speed) << endl;
    return 0;
}
