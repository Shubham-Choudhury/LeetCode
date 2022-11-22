// Link: https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/?envType=study-plan&id=binary-search-ii

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int rangeSum(vector<int> &nums, int n, int left, int right)
    {
        vector<int> sums{};
        for (int i = 0; i < n; i++)
        {
            int prefixSum = 0;
            for (int j = i; j < n; j++)
            {
                prefixSum += nums[j];
                sums.push_back(prefixSum);
            }
        }
        sort(begin(sums), end(sums));
        int res = accumulate(sums.begin() + left - 1, sums.begin() + right, 0LL) % 1000000007;
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 4};
    int n = 4;
    int left = 1;
    int right = 5;
    cout << s.rangeSum(nums, n, left, right) << endl;
    return 0;
}