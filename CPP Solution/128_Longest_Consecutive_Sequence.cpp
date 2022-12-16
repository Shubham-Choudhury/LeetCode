// Link: https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int res = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(nums[i]) != m.end())
                continue;
            int left = m.find(nums[i] - 1) != m.end() ? m[nums[i] - 1] : 0;
            int right = m.find(nums[i] + 1) != m.end() ? m[nums[i] + 1] : 0;
            int sum = left + right + 1;
            m[nums[i]] = sum;
            res = max(res, sum);
            m[nums[i] - left] = sum;
            m[nums[i] + right] = sum;
        }
        return res;
    }
};

int main()
{
    Solution a;
    vector<int> b = {100, 4, 200, 1, 3, 2};
    cout << a.longestConsecutive(b) << endl;
    return 0;
}
