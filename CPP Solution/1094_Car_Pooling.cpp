// Link: https://leetcode.com/problems/car-pooling/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        int n = trips.size();
        vector<pair<int, int>> items;
        for (int i = 0; i < n; i++)
        {
            items.push_back({trips[i][1], trips[i][0]});
            items.push_back({trips[i][2], -trips[i][0]});
        }
        sort(items.begin(), items.end());
        int cur = 0;
        for (int i = 0; i < items.size(); i++)
        {
            cur += items[i].second;
            if (cur > capacity)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> trips;
    int capacity;
    cin >> capacity;
    int n;
    cin >> n;
    trips.resize(n);
    for (int i = 0; i < n; i++)
    {
        trips[i].resize(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> trips[i][j];
        }
    }
    cout << sol.carPooling(trips, capacity) << endl;
    return 0;
}
