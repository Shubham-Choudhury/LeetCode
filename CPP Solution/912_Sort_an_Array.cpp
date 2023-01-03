// Link: https://leetcode.com/problems/sort-an-array/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {5, 2, 3, 1};
    vector<int> ans = S.sortArray(nums);
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
    return 0;
}
