// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumEffort(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] - a[0] > b[1] - b[0];
        });
        int ans = 0, sum = 0;
        for (auto &task : tasks)
        {
            ans = max(ans, sum + task[1]);
            sum += task[0];
        }
        return ans;
    }
};

int main()
{
    Solution a;
    vector<vector<int>> b = {{1, 2}, {2, 4}, {4, 8}};
    cout << a.minimumEffort(b) << endl;
    return 0;
}
