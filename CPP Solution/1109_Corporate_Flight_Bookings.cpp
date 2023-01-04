// Link: https://leetcode.com/problems/corporate-flight-bookings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> ans(n);
        for (auto &booking : bookings)
        {
            ans[booking[0] - 1] += booking[2];
            if (booking[1] < n)
            {
                ans[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; i++)
        {
            ans[i] += ans[i - 1];
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> bookings;
    int n;
    cin >> n;
    int m;
    cin >> m;
    bookings.resize(m);
    for (int i = 0; i < m; i++)
    {
        bookings[i].resize(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> bookings[i][j];
        }
    }
    vector<int> ans = sol.corpFlightBookings(bookings, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
