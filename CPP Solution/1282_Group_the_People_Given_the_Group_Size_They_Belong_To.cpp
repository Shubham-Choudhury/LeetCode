// Link: https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
            mp[groupSizes[i]].push_back(i);
        for (auto i : mp)
        {
            int size = i.first;
            vector<int> temp;
            for (auto j : i.second)
            {
                temp.push_back(j);
                if (temp.size() == size)
                {
                    ans.push_back(temp);
                    temp.clear();
                }
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> groupSizes = {3, 3, 3, 3, 3, 1, 3};
    Solution *obj = new Solution();
    vector<vector<int>> ans = obj->groupThePeople(groupSizes);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
