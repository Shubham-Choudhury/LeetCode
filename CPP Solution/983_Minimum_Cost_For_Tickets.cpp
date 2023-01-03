// Link: https://leetcode.com/problems/minimum-cost-for-tickets/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dp;
    // memoization based solution
    int f(int start, vector<int> &days, vector<int> &costs)
    {

        int n = days.size();

        //  if index(start) is greater then total number of days return 0
        if (start >= n)
            return 0;

        // we aready knows the answer so no need to re calculate
        if (dp[start])
            return dp[start];

        // For a single day
        int one = costs[0] + f(start + 1, days, costs);
        // For a week we have to check how many days are lesser than 7 days

        int i;
        for (i = start; i < n && days[i] < days[start] + 7; i++)
            ;
        // The i index will pointing the maximum days with in the week
        int week = costs[1] + f(i, days, costs);

        // For a month we have to check how many days are lesser than 30 days
        for (i = start; i < n && days[i] < days[start] + 30; i++)
            ;
        // The i index will pointing the maximum days with in the month
        int month = costs[2] + f(i, days, costs);

        // Calculating the min of the day , week , month
        dp[start] = min(one, min(week, month));
        // Return the answer
        return dp[start];
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // Resize the dp array to 1 to 365 :- Total number of days
        dp.resize(366);

        // Starting from 0 index
        return f(0, days, costs);
    }
};

int main()
{
    Solution sol;
    vector<int> days = {1, 4, 6, 7, 8, 20};
    vector<int> costs = {2, 7, 15};
    cout << sol.mincostTickets(days, costs) << endl;
    return 0;
}
