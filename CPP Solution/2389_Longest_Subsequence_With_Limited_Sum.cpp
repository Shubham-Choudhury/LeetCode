// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];

        for (auto i : queries)
        {
            int count = 0;
            int k;
            for (k = 0; k < nums.size(); k++)
            {
                if (count + nums[k] > i)
                    break;
            }
            ans.push_back(k);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> queries = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> ans = s.answerQueries(nums, queries);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}