// Link: https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> pos;
        for (int i = 0; i < target.size(); i++)
        {
            pos[target[i]] = i;
        }
        vector<int> d;
        for (int x : arr)
        {
            if (pos.count(x))
            {
                int idx = pos[x];
                auto it = lower_bound(d.begin(), d.end(), idx);
                if (it != d.end())
                {
                    *it = idx;
                }
                else
                {
                    d.push_back(idx);
                }
            }
        }
        return target.size() - d.size();
    }
};

int main()
{
    Solution sol;
    vector<int> target, arr;
    int result;

    // Output: 2
    target = {5, 1, 3}, arr = {9, 4, 2, 3, 4};
    result = sol.minOperations(target, arr);
    cout << result << endl;

    // Output: 1
    target = {6, 4, 8, 1, 3, 2}, arr = {4, 7, 6, 2, 3, 8, 6, 1};
    result = sol.minOperations(target, arr);
    cout << result << endl;

    // Output: 3
    target = {3, 1, 5, 4, 2}, arr = {6, 5, 4, 3, 2, 8, 7, 1};
    result = sol.minOperations(target, arr);
    cout << result << endl;

    return 0;
}
