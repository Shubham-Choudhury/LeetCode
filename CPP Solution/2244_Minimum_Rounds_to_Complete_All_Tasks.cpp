// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        map<int, int> mp;
        for (int i = 0; i < tasks.size(); i++)
        {
            mp[tasks[i]]++;
        }

        int output = 0;

        for (auto freq : mp)
        {
            if (freq.second == 1)
                return -1;
            if (freq.second % 3 == 0)
            {
                output += freq.second / 3;
            }
            else
            {
                output += freq.second / 3 + 1;
            }
        }
        return output;
    }
};

int main()
{
    Solution s;
    vector<int> tasks = {1, 2, 3, 4, 5};
    cout << s.minimumRounds(tasks) << endl;
    return 0;
}
