// Link: https://leetcode.com/problems/remove-covered-intervals/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 0, right = 0;
        for (auto i : intervals)
            if (i[1] > right)
                ans++, right = i[1];
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 4}, {3, 6}, {2, 8}};
    Solution *obj = new Solution();
    cout << obj->removeCoveredIntervals(intervals) << endl;
    return 0;
}
